/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:03:21 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/24 23:03:43 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mlx_exit(t_mlx *m)
{
	mlx_destroy_image(m->mlx, m->img);
	mlx_destroy_window(m->mlx, m->mlx_win);
	free(m->mlx);
	exit(EXIT_SUCCESS);
}