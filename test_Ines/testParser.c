
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "cub3d.h"
#include <string.h>
#include <stdlib.h>

#pragma region texts

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
    if (test[0] != ' ' && test[0] != '\t')
    {
        printf("Texture: Invalid character\n");
        return NULL;
    }
    length = ft_strlen(test);
    while (test[i] != '.')
    {
        if (test[i] != ' ' && test[i] != '\t')
        {
            printf("Texture: Invalid character\n");
            return NULL;
        }
        i++;
    }
    if (i == length || test[i + 1] != '/')
    {
        printf("Texture: no path found\n");
        return (NULL);
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

    while (test[*i] == ' ' || test[*i] == '\t')
        (*i)++;
    init = *i;
    while (test[*i] >= '0' && test[*i] <= '9')
        (*i)++;
    if (*i == init)
    {
        printf("Color: Character not valid\n");
        return (-1);
    }
    final = *i;
    while (test[*i] != ',' && test[*i] != '\n' && test[*i] != '\0')
    {
        if (test[*i] != ' ' && test[*i] != '\t')
        {
            printf("Color: character not valid\n");
            return (-1);
        }
        (*i)++;
    }
    str = (char *)malloc(sizeof(char) * (final - init + 1));
    str = &test[init];
    str[final - init] = '\0';
    return (ft_atoi(str));
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
        printf("Color:error!\nRGB needs to be between 0 and 255\n");
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
        printf("Color: Character not valid\n");
        return (1);
    }
    i = 2;
    color.r = get_factors_rgb(&i, test);
    i++;
    color.g = get_factors_rgb(&i, test);
    i++;
    color.b = get_factors_rgb(&i, test);
    if (color.r < 0 || color.g < 0 || color.b < 0)
    {
        printf("Color: Rgb not valid!\n");
        return 1;
    }
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
    int i;

    i = 0;
    if (!ft_strncmp(test, "NO", 2) || !ft_strncmp(test, "SO", 2) || !ft_strncmp(test, "EA", 2) || !ft_strncmp(test, "WE", 2))
        return (get_textures(test, map));
    else if(!ft_strncmp(test, "F", 1) || !ft_strncmp(test, "C", 1))
        return (get_colors(test, map));
    else if(ft_strncmp("\n", test, 1))
    {
        while((test[i] == ' ' || test[i] == '\t') && test[i] != '\n')
            i++;
        if (i == ft_strlen(test))
            return (0);
        printf("Error!\nCharacters not known\n");
        return (1);
    }
    return 0;
}
#pragma endregion

#pragma region map

int check_characters(char *map_test)
{
    int i;
    int a;

    i = 0;
    a = 0;
    while(map_test[i] != '\0')
    {
        if (map_test[i] != '0' && map_test[i] != '1' && map_test[i] != ' ' && map_test[i] != 'N' && \
        map_test[i] != 'S' && map_test[i] != 'E' && map_test[i] != 'W' && map_test[i] != '\n')
        {            
            printf("Map: Character not valid\n");
            return (1);
        }
        if ((map_test[i] == 'N' || map_test[i] == 'S' || map_test[i] == 'E' || map_test[i] == 'W'))
            a++;
        i++;
    }
    if (a == 0)
    {
        printf("Map: There is no spot for the player\n");
        return (1);
    }
    else if (a > 1)
    {
         printf("Map: More than one player\n");
        return (1);
    }
    return (0);
}

int max_length_line(char *map_test)
{
    int i;
    int a;
    int max_length;

    i = 0;
    a = 0;
    max_length = 0;
    while (map_test[i] != '\0')
    {
        if (map_test[i] == '\n')
        {
            if (max_length < (i - a))
                max_length = i - a;
            a = i + 1;
        }
        i++;
    }
    if (max_length < i - a)
        max_length = i - a;
    return (max_length);
}

int number_of_lines(char *map_test)
{
    int i;
    int line;

    i = 0;
    line = 0;
    while (map_test[i] != '\0')
    {
        if (map_test[i] == '\n')
            line++;
        i++;
    }
    return (line + 1);
}

char *copy_map(char *map_test, int *j, int max_length)
{
    int i;
    char *new_map;

    i = 0;
    new_map = malloc(sizeof(char) * (max_length + 1));
    while (map_test[(*j)] != '\0' && map_test[(*j)] != '\n')
    {
        new_map[i] = map_test[(*j)];
        i++; 
        (*j)++;
    }
    while (i < max_length)
    {
        new_map[i] = ' ';
        i++;
    }
    (*j)++;
    new_map[i] = '\0';
    return (new_map);
}

char **build_map(char *map_test, int lines, int max_length)
{
    char **map;
    int i;
    int j;
    char *test;

    i = 0;
    map = malloc(sizeof(char *) * (lines + 1));
    while (i < lines)
    {
        map[i] = malloc(sizeof(char) * (max_length + 1));
        i++;
    }
    i = 0;
    j = 0;
    while (i < lines)
    {   
        test = copy_map(map_test, &j, max_length);
        map[i] = ft_strdup(test);
        free(test);
        test = NULL;
        i++;
    }
    map[i] = 0;
    return (map);
}

int f_fill(char **map, int max_length, int lines, int x, int y)
{
    //static int a;

    //if (a == 1)
      //  return (1);
    if (x < 0 || y < 0 || x > (max_length - 1) || y > (lines - 1))
        return (0);
    if (map[y][x] == 'F' || map[y][x] != '0')
        return (0);
    if (y == 0 || y == (lines - 1) || x == 0 || x == (max_length - 1))
    {
        printf("Map: ZeroTest :Invalid map.\n");
        //a = 1;
        return (1);
    }
    map[y][x] = 'F';
   // a = 0;
    if (map[y - 1][x] == ' ' || map[y][x - 1] == ' ' || map[y + 1][x] == ' ' || map[y][x + 1] == ' ' || \
    map[y - 1][x] == '\0' || map[y][x - 1] == '\0' || map[y + 1][x] == '\0' || map[y][x + 1] == '\0')
    {
        printf("Map: Zero:Invalid map.\n");
       // a = 1;
        return (1);
    }

    f_fill(map, max_length, lines, x - 1, y);
    f_fill(map, max_length, lines, x + 1, y);
    f_fill(map, max_length, lines, x, y - 1);
    f_fill(map, max_length, lines, x, y + 1);
    return (0);
}

int find_char(char **map, int *x, int *y, char find)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[j] != 0)
    {
        i = 0;
        while (map[j][i] != '\0')
        {
            if (map[j][i] == find)
            {
                *x = i;
                *y = j;
                return (0);
            }
            i++;
        }
        j++;
    }
    return (1);
}

int floodfill(char **map, int max_length, int lines)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (!find_char(map, &x, &y, '0'))
    {
        if (f_fill(map, max_length, lines, x, y))
            return (1);
    }
    x = 0;
    y = 0;
    if (find_char(map, &x, &y, 'N'))
        if (find_char(map, &x, &y, 'S'))
            if (find_char(map, &x, &y, 'W'))
                find_char(map, &x, &y, 'E');
    if (y == 0 || x == 0 || y == (lines - 1) || x == (max_length - 1))
    {
        printf("Map: Player: Invalid map.\n");
        return (1);
    }
    else if (map[y - 1][x] == ' ' || map[y][x - 1] == ' ' || map[y + 1][x] == ' ' || map[y][x + 1] == ' ' || 
    map[y - 1][x] == '\0' || map[y][x - 1] == '\0' || map[y + 1][x] == '\0' || map[y][x + 1] == '\0')
    {
        printf("Map: Player: Invalid map.\n");
        return (1);
    }
    return (0);
}

int parse_map(char *map_test, t_map *map)
{
    int max_length;
    int lines;

    if (check_characters(map_test))
        return (1);
    max_length = max_length_line(map_test);
    lines = number_of_lines(map_test);
    map->worldmap = build_map(map_test, lines, max_length);  
    if (floodfill(map->worldmap, max_length, lines))
       return (1);
    int i = 0;
    while (map->worldmap[i] != 0)
    {
        printf("%d, %s\n", i, map->worldmap[i]);
        i++;
    }
    return (0);
}

#pragma endregion

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

    while (!map->e_texture || !map->w_texture || !map->s_texture \
    || !map->n_texture || !map->color_c || !map->color_f)
    {
        test = get_next_line(fd);
        if (!test)
        {
            printf("There is no map!\n");
            return (1);
        }
        test = ft_strtrim(test, " ");
        test = ft_strtrim(test, "\t");
        if (save_value(test, map))
            return (1);
        free(test);
    }

    test = NULL;
    char *map_test;
    int i = 0;
    while (!test)
    {
        test = get_next_line(fd);
        if (test[i] == ' ' || test[i] == '\t' || test[i] == '\n')
        {
            if (test[0] == '\n')
            {
                free(test);
                test = NULL;
            }
			else
			{
            	while (test[i] == ' ' || test[i] == '\t')
                	i++;
            	if (i == ft_strlen(test) - 1 && test[i - 1] == '\n')
            	{
					i = 0;
                	free(test);
                	test = NULL;
            	}
				else if (i == ft_strlen(test))
				{
					i = 0;
                	free(test);
                	test = NULL;
				}
			}
        }
    }
    
    i = 0;
    map_test = ft_strdup(test);
    while (test)
    {
        free(test);
        test = NULL;
        test = get_next_line(fd);
        map_test = ft_strjoin(map_test, test);
    }
   // printf("%s\n", map_test);
   	ft_strtrim(map_test, "\n");
    if (parse_map(map_test, map))
        return (1);
    
/*
    printf("\n\n%s\n", map->n_texture);
    printf("%s\n", map->s_texture);
    printf("%s\n", map->w_texture);
    printf("%s\n", map->e_texture);
    printf("%s\n", map->color_c);
    printf("%s\n", map->color_f);*/
    return (0);
}