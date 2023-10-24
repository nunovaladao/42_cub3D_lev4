/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:01:09 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/23 23:46:25 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		check_file(char *file)
{
    int		fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Error!\nFile not found...\n");
        return (1);
    }
    close(fd);
    return (0);
}

int check_file_extension(char *file_name)
{
    int i;

    i = 0;
    while (file_name[i])
        i++;
    if (file_name[i - 1] != 'b' || file_name[i - 2] != 'u' || file_name[i - 3] != 'c' || file_name[i - 4] != '.')
    {
        printf("Error!\nFile extension not valid...\n");
        return (1);
    }
    return (0);
}
