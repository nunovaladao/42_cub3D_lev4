/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:50:57 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/27 23:36:05 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void print_world_map(t_map *map) 
{
    for (int i = 0; i < map->nr_rows; i++) 
    {
        printf("%s", map->worldMap[i]);
    }
}

int get_rows(t_map *map)
{
    int fd;
    char *line;

    fd = open(map->map_file, O_RDONLY);
    if (read(fd, &line, 1) == 0)
    {
        close(fd);
        printf("Error!\nMap file is empty\n");
        exit(0);
    }
    while ((line = get_next_line(fd)))
    {
        map->nr_rows++;
        free(line);
    }
    close(fd);
    return (map->nr_rows);
}

void get_map(t_map *map)
{
    int fd;
    fd = open(map->map_file, O_RDONLY);
    char *line = get_next_line(fd);
    int i;
    int j;

    i = -1;
    while ((line) && ++i < map->nr_rows)
    {
        map->worldMap[i] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
        j = 0;
        while (line[j])
        {
            map->worldMap[i][j] = line[j];
            j++;
        }
        map->worldMap[i][j] = '\0';
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}

void get_map_file(t_map *map)
{
    map->nr_rows = get_rows(map);
    map->worldMap = ft_calloc(map->nr_rows, sizeof(char *));
    if (!map->worldMap)
    {
        printf("Error!\nMalloc failed\n");
        exit(0);
    }
    get_map(map);
}

void check_map(t_map *map)
{
    get_map_file(map);
    /* print_world_map(map);
    puts(""); */
    
}
