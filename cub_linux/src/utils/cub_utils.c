/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:03:21 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/29 16:34:14 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	small_free(t_mlx *mlx, t_map *map)
{
	if (mlx->data->text)
		free(mlx->data->text);
	free_map(map);
	exit(1);
}

void	mlx_exit(t_mlx *m)
{
	int	i;

	i = -1;
	if (m->mlx)
		mlx_clear_window(m->mlx, m->mlx_win);
	if (m->mlx)
		mlx_destroy_window(m->mlx, m->mlx_win);
	if (m->mlx)
		mlx_destroy_image(m->mlx, m->img);
	while (++i < 4)
	{
		if (m->data->text[i].img)
			mlx_destroy_image(m->mlx, m->data->text[i].img);
	}
	if (m->mlx_win)
		mlx_destroy_display(m->mlx);
	if (m->data->text)
		free(m->data->text);
	free_map(m->data->map);
	free(m->mlx);
	exit(EXIT_SUCCESS);
}
