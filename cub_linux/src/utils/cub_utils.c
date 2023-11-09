/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:03:21 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/09 23:10:10 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		mlx_destroy_image(m->mlx, m->data->text[i].img);
	if (m->mlx_win)
		mlx_destroy_display(m->mlx);
	if (m->data->text)
		free(m->data->text);
	free_map(m->data->map);
	free(m->mlx);
	exit(EXIT_SUCCESS);
}
