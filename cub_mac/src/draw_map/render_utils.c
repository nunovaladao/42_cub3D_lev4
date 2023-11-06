/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:16:56 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/06 15:15:02 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void draw_texture(t_data *d)
{
    //x coordinate on the texture
    d->texX = (int)(d->map->wallX * (double)texWidth);
	if (d->side == '0' && d->rayDirX > 0)
		d->texX = texWidth - d->texX - 1;
	if (d->side == '1' && d->rayDirY < 0)
		d->texX = texWidth - d->texX - 1;

		// How much to increase the texture coordinate per screen pixel
	d->map->step = 1.0 * texHeight / d->lineHeight;
		// Starting texture coordinate
	d->map->texPos = (d->drawStart - (double)screenHeight / 2 + (double)d->lineHeight / 2) * d->map->step;

	int y = d->drawStart - 1;
	while (++y < d->drawEnd)
	{
		int texY = (int)d->map->texPos & (texHeight - 1);
		d->map->texPos += d->map->step;

		if (d->side == '0' && d->rayDirX > 0)
			my_mlx_pixel_put(d->mlx, d->x, y, (unsigned int)my_mlx_pixel_get(&d->text[SOUTH], d->texX, texY));
		else if (d->side == '0' && d->rayDirX < 0)
			my_mlx_pixel_put(d->mlx, d->x, y, (unsigned int)my_mlx_pixel_get(&d->text[NORTH], d->texX, texY));
		else if (d->side == '1' && d->rayDirY > 0)
			my_mlx_pixel_put(d->mlx, d->x, y, (unsigned int)my_mlx_pixel_get(&d->text[EAST], d->texX, texY));
		else if (d->side == '1' && d->rayDirY < 0)
			my_mlx_pixel_put(d->mlx, d->x, y, (unsigned int)my_mlx_pixel_get(&d->text[WEST], d->texX, texY));
	}
}

void calc_wall_pixel(t_data *d)
{
    //Calculate height of line to draw on screen
	d->lineHeight = (int)(screenHeight / d->perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	d->drawStart = -d->lineHeight / 2 + screenHeight / 2;

	if (d->drawStart < 0)
		d->drawStart = 0;

	d->drawEnd = d->lineHeight / 2 + screenHeight / 2;

	if (d->drawEnd >= screenHeight)
		d->drawEnd = screenHeight - 1;

	//calculate value of wallX
	//double wallX; //where exactly the wall was hit
	if (d->side == '0')
		d->map->wallX = d->posY + d->perpWallDist * d->rayDirY;
	else
		d->map->wallX = d->posX + d->perpWallDist * d->rayDirX;
	d->map->wallX -= floor((d->map->wallX));
}

void check_side(t_data *d)
{
    if (d->rayDirX < 0)
    {
        d->stepX = -1;
        d->sideDistX = (d->posX - d->mapX) * d->deltaDistX;
    }
    else
    {
        d->stepX = 1;
        d->sideDistX = (d->mapX + 1.0 - d->posX) * d->deltaDistX;
    }
    if (d->rayDirY < 0)
    {
        d->stepY = -1;
        d->sideDistY = (d->posY - d->mapY) * d->deltaDistY;
    }
    else
    {
        d->stepY = 1;
        d->sideDistY = (d->mapY + 1.0 - d->posY) * d->deltaDistY;
    }
}

void calculations(t_data *d)
{
    d->cameraX = 2 * (double)d->x / (double)screenWidth - 1; //d->-coordinate in camera space
    d->rayDirX = d->dirX + d->planeX * d->cameraX;
    d->rayDirY = d->dirY + d->planeY * d->cameraX;
    d->mapX = (int)d->posX;
    d->mapY = (int)d->posY;
    /* if (d->rayDirX == 0)
        d->deltaDistX = 1e30;
    else */
        d->deltaDistX = fabs(1.0 / d->rayDirX);

    /* if (d->rayDirY == 0)
         d->deltaDistY = 1e30;
    else */
        d->deltaDistY = fabs(1.0 / d->rayDirY);

    check_side(d);
}

void perform_dda(t_data *d)
{
    d->hit = '0'; //was there a wall hit?
    while (d->hit == '0')
	{
			//jump to next map square, either in x-direction, or in y-direction
		if (d->sideDistX < d->sideDistY)
		{
			d->sideDistX += d->deltaDistX;
			d->mapX += d->stepX;
			d->side = '0';
		}
		else
		{
			d->sideDistY += d->deltaDistY;
			d->mapY += d->stepY;
            d->side = '1';
		}
		//Check if ray has hit a wall
		if (d->map->worldMap[d->mapX][d->mapY] > '0')
			d->hit = '1';
	}
    if (d->side == '0')
		d->perpWallDist = (d->sideDistX - d->deltaDistX);
    else
		d->perpWallDist = (d->sideDistY - d->deltaDistY);
}
