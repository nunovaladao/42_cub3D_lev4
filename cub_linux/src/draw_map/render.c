/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:45:29 by nsoares-          #+#    #+#             */
/*   Updated: 2023/11/02 17:25:09 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int render_next_frame(void *param)
{
	t_data *d = param;

    background(d->mlx);
    
	/* double posX = 22, posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; */ //the 2d raycaster version of camera plane

	int x = -1;
	while (++x < SCREENWIDTH)
    {
      	//calculate ray position and direction
    	d->cameraX = 2 * x / (double)SCREENWIDTH - 1; //x-coordinate in camera space
    	d->rayDirX = d->dirX + d->planeX * d->cameraX;
    	d->rayDirY = d->dirY + d->planeY * d->cameraX;

		//which box of the map we're in
      	d->mapX = (int)d->posX;
      	d->mapY = (int)d->posY;

      	//length of ray from current position to next x or y-side
      	/* double sideDistX;
      	double sideDistY; */

       	//length of ray from one x or y-side to next x or y-side
		//double deltaDistX = 0;

		if (d->rayDirX == 0)
			d->deltaDistX = 1e30;
		else
			d->deltaDistX = fabs(1.0 / d->rayDirX);

		//double deltaDistY = 0;
		if (d->rayDirY == 0)
			d->deltaDistY = 1e30;
		else
			d->deltaDistY = fabs(1.0 / d->rayDirY);

		//double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		/* int stepX;
		int stepY; */

		//calculate step and initial sideDist
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

		d->hit = '0'; //was there a wall hit?
		//int side; //was a NS or a EW wall hit?
		
		//perform DDA
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

		// int pitch = 100;

		//Calculate height of line to draw on screen
		d->lineHeight = (int)(SCREENHEIGHT / d->perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		d->drawStart = -d->lineHeight / 2 + SCREENHEIGHT / 2;

		if (d->drawStart < 0)
			d->drawStart = 0;

		d->drawEnd = d->lineHeight / 2 + SCREENHEIGHT / 2;

		if (d->drawEnd >= SCREENHEIGHT)
			d->drawEnd = SCREENHEIGHT - 1;

		//calculate value of wallX
		//double wallX; //where exactly the wall was hit
		if (d->side == '0')
			d->map->wallX = d->posY + d->perpWallDist * d->rayDirY;
		else
			d->map->wallX = d->posX + d->perpWallDist * d->rayDirX;
		d->map->wallX -= floor((d->map->wallX));

		//x coordinate on the texture
		d->texX = (int)(d->map->wallX * (double)TEXWIDTH);
		if (d->side == '0' && d->rayDirX > 0)
			d->texX = TEXWIDTH - d->texX - 1;
		if (d->side == '1' && d->rayDirY < 0)
			d->texX = TEXWIDTH - d->texX - 1;

		// How much to increase the texture coordinate per screen pixel
		d->map->step = 1.0 * TEXTHEIGHT / d->lineHeight;
		// Starting texture coordinate
		d->map->texPos = (d->drawStart - SCREENHEIGHT / 2 + d->lineHeight / 2) * d->map->step;


		int y = d->drawStart;
		while (y < d->drawEnd)
		{
			int texY = (int)d->map->texPos & (TEXTHEIGHT - 1);
			d->map->texPos += d->map->step;

			if (d->side == '0' && d->rayDirX < 0)
				my_mlx_pixel_put(d->mlx, x, y, (unsigned int)my_mlx_pixel_get(&d->text[NORTH], d->texX, texY));
			else if (d->side == '0' && d->rayDirX > 0)
				my_mlx_pixel_put(d->mlx, x, y, (unsigned int)my_mlx_pixel_get(&d->text[SOUTH], d->texX, texY));
			else if (d->side == '1' && d->rayDirY > 0)
				my_mlx_pixel_put(d->mlx, x, y, (unsigned int)my_mlx_pixel_get(&d->text[EAST], d->texX, texY));
			else if (d->side == '1' && d->rayDirY < 0)
				my_mlx_pixel_put(d->mlx, x, y, (unsigned int)my_mlx_pixel_get(&d->text[WEST], d->texX, texY));
			y++;
		}
	}
	//mlx_put_image_to_window(d->mlx->mlx, d->mlx->mlx_win, d->mlx->img, 0, 0);

	d->moveSpeed = 0.05; //the constant value is in squares/second
    d->rotSpeed = 0.01; //the constant value is in radians/second

	//move_camera(d);

    return (0);
}