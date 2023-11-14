#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "cub3d.h"
#include <string.h>
#include <stdlib.h>


#pragma region textures
/** @brief gets string from test for the textures
* Checks first if there is a path. THen mallocs
* a new string and writes in it
* @returns NULL on error.
* */
char *get_string(char *test)
{
    int i;
    int length;
    char *new;
    int j;

    i = 0;
    if (test[0] != ' ' || test[0] != '\t')
    {
        printf("character not correct\n");
        return NULL;
    }
    length = ft_strlen(test);
    while (test[i] != '.')
    {
        if (test[i] != ' ')
        {
            printf("character not correct\n");
            return NULL;
        }
        i++;
    }
    if (i == length || test[i + 1] != '/')
    {
        printf("wrong path\n");
        return NULL;
    }
    new = (char *)malloc(sizeof(char) * (length - i));
    i += 2;
    j = 0;
    while (test[i] != '\n')
    {
        new[j] = test[i];
        i++;
        j++;
    }
    new[j] = '\0';
    return new;
}

/** @brief checks which texture to get
* @returns 1 on error, else 0
* */
int get_textures(char *test, t_map *map)
{
    char *texture;

    texture = get_string(&test[2]);
    if (!texture)
        return (1);
    if (!ft_strncmp(test, "NO", 2)) 
        map->n_texture = texture;
    else if (!ft_strncmp(test, "SO", 2))
        map->s_texture = texture;
    else if (!ft_strncmp(test, "WE", 2))
        map->w_texture = texture;
    else if (!ft_strncmp(test, "EA", 2)) 
        map->e_texture = texture;
    return (0);
}
#pragma endregion

#pragma region colors
/** @brief tranform the number to integers
* */
int get_factors_rgb(int *i, char *test)
{
    int init;
    int final;
    char *str;

    while (test[*i] == ' ')
        (*i)++;
    init = *i;
    while (test[*i] != ',' && test[*i] != '\n' && test[*i] != '\0'&& test[*i] != ' ' && test[*i] != '\t')
    {
        if ((test[*i] < '0' || test[*i] > '9'))
        {
            printf("Error in color\n");
            return (-1);
        }
        (*i)++;
    }
    final = *i;
    str = (char *)malloc(sizeof(char) * (final - init + 1));
    str = &test[init];
    str[final - init] = '\0';
    return (ft_atoi(str)); //atoi
}

/** @brief with a base transform rgb to hexa
* */
void get_hexa_parts(int *i, char **hexa, int color)
{
    char *base;
    char *str;
    int j = 0;

    base = (char *)malloc(sizeof(char) * 16);
    base = "0123456789ABCDEF\0";
    str = malloc(sizeof(char) * 3);
    str[j] = base[color / 16];
    j++;
    str[j] = base[color % 16];
    j++;
    str[j] = '\0';
    j = 0;
    while (str[j] != '\0')
    {
        *(*(hexa) + (*i)) = str[j];
        j++;
        (*i)++; 
    }
    free (str);
   //free(base);
}

/** @brief returns a string of an hexa
* */
char *get_hexa(t_rgb color)
{
    char *hexa;
    int i;

    if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 || color.b < 0 || color.b > 255 )
    {
        printf("error!\nRGB Invalid\n");
        return (NULL);
    }
    hexa = ft_calloc(sizeof(char), 3); 
    i = 0;
    get_hexa_parts(&i, &hexa, color.r);
    get_hexa_parts(&i, &hexa, color.g);
    get_hexa_parts(&i, &hexa, color.b);
    hexa[i] = '\0';
    return (hexa);
}

/** @brief first creates rgb then the hexa 
* */
int get_colors(char *test, t_map *map)
{
    int i;
    char *str;
    t_rgb color;

    if (test[1] != ' ' && test[1] != '\t')
    {
        printf("Error in color\n");
        return (1);
    }
    i = 2;
    color.r = get_factors_rgb(&i, test);
    i++;
    color.g = get_factors_rgb(&i, test);
    i++;
    color.b = get_factors_rgb(&i, test);
    if (color.r < 0 || color.g < 0 || color.b < 0)
        return 1;
    str = get_hexa(color);
    if (!str)
        return (1);
    if (ft_strchr(test, 'F'))
        map->color_f = str;
    else
        map->color_c = str;
    return 0;
}

#pragma endregion

/** @brief separates the options between all the options
* @return 1 on error else 0
* */
int save_value(char *test, t_map *map)
{
    int length;
    int i;

    i = 0;
    if (!ft_strncmp(test, "NO", 2) || !ft_strncmp(test, "SO", 2) || !ft_strncmp(test, "EA", 2) || !ft_strncmp(test, "WE", 2))
        return (get_textures(test, map));
    else if(!ft_strncmp(test, "F", 1) || !ft_strncmp(test, "C", 1))
        return (get_colors(test, map));
    else if(ft_strncmp("\n", test, 1))
    {
        length = ft_strlen(test);
        while((test[i] == ' ' || test[i] == '\t') && test[i] != '\n')
            i++;
        if (i == length)
            return (0);
        printf("Error!\nCharacters not known\n");
        return (1);
    }
    return 0;
}

int main(int argc, char *argv[], char *envp[])
{
    char *test;
    int fd;
    t_map *map;

    fd = open(argv[1], O_RDWR);
    map = (t_map *)malloc(sizeof(t_map));
    test = get_next_line(fd);
    if (!test)
    {
        printf("Error!\nFile Empty\n");
        return (1);
    }
    test = ft_strtrim(test, " ");
    test = ft_strtrim(test, "\t");
    if (save_value(test, map))
        return 1;
    while (test)
    {
        test = get_next_line(fd);
        if (!test)
            break ;
        test = ft_strtrim(test, " ");
        test = ft_strtrim(test, "\t");
        if (save_value(test, map))
            return (1);
        free(test);
    }
    printf("\n\n%s\n", map->n_texture);
    printf("%s\n", map->s_texture);
    printf("%s\n", map->w_texture);
    printf("%s\n", map->e_texture);
}