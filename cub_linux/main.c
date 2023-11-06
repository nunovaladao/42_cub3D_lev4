/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:48:39 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/03 18:00:36 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int game(t_data *data)
{
	update_moves(data, data->rot);
	render_next_frame(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->img, 0, 0);
	return (0);
}

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

	mlx_hook(mlx.mlx_win, 2, 1L << 0, keyboard_hook, &mlx);
	mlx_hook(mlx.mlx_win, 3, 1L << 1, keyboard_keyrelease, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, (void *)mlx_exit, &mlx);
	mlx_loop_hook(mlx.mlx, game, &data);
	mlx_loop(mlx.mlx);
    return (0);
}
