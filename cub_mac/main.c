/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:48:39 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/31 14:45:21 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	data;
	t_mlx	mlx;
	t_map	map;

	if (check_args(ac, av) == 1)
		exit(1);
	init_all(&mlx, &data, &map);
	// check / read map
	map.map_file = av[1];
	check_map(&map);

	open_window(&mlx);
	init_textures(&data);
	
	mlx_hook(mlx.mlx_win, 2, 0, keyboard_hook, &mlx);
	mlx_hook(mlx.mlx_win, 3, 0, keyboard_keyrelease, &mlx);
	mlx_loop_hook(mlx.mlx, render_next_frame, &data);
    hook_events(&mlx);
	mlx_loop(mlx.mlx);
    
    return (0);
}
