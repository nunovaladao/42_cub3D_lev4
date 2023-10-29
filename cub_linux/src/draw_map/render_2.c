/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:54 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/27 14:14:37 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int render_next_frame(void *param)
{
	t_data *d = param;

    background(d->mlx);
    
	//double posX = 22, posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	//double time = 0; //time of current frame
  	//double oldTime = 0; //time of previous frame

	for (int x = 0; x < screenWidth; x++)
    {
      	//calculate ray position and direction
    	double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
    	double rayDirX = dirX + planeX * cameraX;
    	double rayDirY = dirY + planeY * cameraX;

		//which box of the map we're in
      	int mapX = (int)d->posX;
      	int mapY = (int)d->posY;

      	//length of ray from current position to next x or y-side
      	double sideDistX;
      	double sideDistY;

       	//length of ray from one x or y-side to next x or y-side
		double deltaDistX = 0;
		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = fabs(1.0 / rayDirX);

		double deltaDistY = 0;
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = fabs(1.0 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (d->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - d->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (d->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - d->posY) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) 
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
      	else
			perpWallDist = (sideDistY - deltaDistY);

		// int pitch = 100;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;

		if (drawStart < 0)
			drawStart = 0;

		int drawEnd = lineHeight / 2 + screenHeight / 2;

		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;

		int wallColors[] = {
			0xFF0000, // Vermelho (parede tipo 1)
			0x00FF00, // Verde (parede tipo 2)
			0x0000FF, // Azul (parede tipo 3)
			0xFFFF00, // Amarelo (parede tipo 4)
			0xFF00FF  // Magenta (parede tipo 5)
    	};

		// draw the walls
		int color = wallColors[worldMap[mapX][mapY] - 1]; // -1 para mapear para o índice do array
		for (int y = drawStart; y < drawEnd; y++)
		{
			my_mlx_pixel_put(d->mlx, x, y, color);
		}
		mlx_put_image_to_window(d->mlx->mlx, d->mlx->mlx_win, d->mlx->img, 0, 0);

		// move player
		

	}
	
    return 0;
}