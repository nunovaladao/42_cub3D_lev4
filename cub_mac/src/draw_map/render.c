/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:29 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:15 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/**
 * @brief Renders the next frame of the game.
 * 
 * @param param The t_data struct.
 * @return int 0 if successful.
 */
int render_next_frame(void *param)
{
	t_data *d = param;

    background(d->mlx); // Draw the background color to the screen.
	d->x = -1;
	while (++d->x < screenWidth) // Loop through each vertical stripe of the screen.
    {
		calculations(d); // Calculate the ray position and direction.
		perform_dda(d); // Perform DDA algorithm.
		calc_wall_pixel(d); // Calculate the height of the wall.
		draw_texture(d); // Draw the texture to the screen.
	}
    return (0);
}
