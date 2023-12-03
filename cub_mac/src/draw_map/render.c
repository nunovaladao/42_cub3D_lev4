/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:29 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/28 22:45:06 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/**
 * @brief Renders the next frame of the game.
 *
 * This function is responsible for rendering 
 * the next frame of the game by performing
 * calculations, raycasting, and drawing textures 
 * on the screen.
 *
 * @param param A pointer to the data structure 
 * containing information about the game.
 * @return int Returns 0 upon successful execution.
 */
int	render_next_frame(void *param)
{
	t_data	*d;

	d = param;
	background(d->mlx);
	d->x = -1;
	while (++d->x < SCREENWIDTH)
	{
		calculations(d);
		perform_dda(d);
		calc_wall_pixel(d);
		draw_texture(d);
	}
	return (0);
}
