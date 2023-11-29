/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:46:44 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/29 13:55:05 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_args(int ac, char **av, t_map *map)
{
	if (ac != 2)
	{
		printf("Error!\nUsage: ./cub3D 'map_path'\n");
		return (1);
	}
	if (check_file(av[1], map) == 1)
		return (1);
	if (check_file_extension(av[1]) == 1)
		return (1);
	return (0);
}
