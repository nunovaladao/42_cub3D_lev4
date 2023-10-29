/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:48:39 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/29 16:55:53 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int convert_color(char color) {
    switch (color) {
        case '1': return 0xFF0000; // Vermelho
        case '2': return 0x00FF00; // Verde
        case '3': return 0x0000FF; // Azul
        case '4': return 0xFFFF00; // Amarelo
        case '5': return 0xFF00FF; // Magenta
        default: return 0xFFFFFF;  // Branco (ou cor padrão)
    }
}

int render_next_frame(void *param)
{
	t_data *d = param;

    background(d->mlx);
    
	/* double posX = 22, posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; */ //the 2d raycaster version of camera plane

	int x = -1;
	while (++x < screenWidth)
    {
      	//calculate ray position and direction
    	d->cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
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
		d->hit = '0'; //was there a wall hit?
		//int side; //was a NS or a EW wall hit?

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
		d->lineHeight = (int)(screenHeight / d->perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		d->drawStart = -d->lineHeight / 2 + screenHeight / 2;

		if (d->drawStart < 0)
			d->drawStart = 0;

		d->drawEnd = d->lineHeight / 2 + screenHeight / 2;

		if (d->drawEnd >= screenHeight)
			d->drawEnd = screenHeight - 1;

		//texturing calculations
		//int texNum = worldMap[d->mapX][d->mapY] - 1; //1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		//double wallX; //where exactly the wall was hit
		if (d->side == '0')
			d->map->wallX = d->posY + d->perpWallDist * d->rayDirY;
		else
			d->map->wallX = d->posX + d->perpWallDist * d->rayDirX;
		d->map->wallX -= floor((d->map->wallX));

		//x coordinate on the texture
		int texX = (int)(d->map->wallX * (double)texWidth);
		if (d->side == '0' && d->rayDirX > 0)
			texX = texWidth - texX - 1;
		if (d->side == '1' && d->rayDirY < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate per screen pixel
		//double step = 1.0 * texHeight / d->lineHeight;
		// Starting texture coordinate
		//double texPos = (d->drawStart - screenHeight / 2 + d->lineHeight / 2) * step;


		// draw the walls
		//int color = wallColors[d->map->worldMap[d->mapX][d->mapY] - 1]; // -1 para mapear para o índice do array
		
		for (int y = d->drawStart; y < d->drawEnd; y++)
		{
			// Calcule a coordenada da textura (texY) a ser mapeada para a parede.
			//int texY = (int)texPos; // Esta é uma simplificação, pode precisar de mais lógica dependendo da escala da textura.
			//texPos += step;

			// Color é a cor da textura na posição (texX, texY).
			// Certifique-se de que texX, texY, e texNum estejam definidos corretamente.
			
			my_mlx_pixel_put(d->mlx, x, y, convert_color(d->map->worldMap[d->mapX][d->mapY]));	
		}
		mlx_put_image_to_window(d->mlx->mlx, d->mlx->mlx_win, d->mlx->img, 0, 0);
	}

	d->moveSpeed = 0.8; //the constant value is in squares/second
    d->rotSpeed = 0.5; //the constant value is in radians/second
	
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
	
	// init textures
	
	mlx_hook(mlx.mlx_win, 2, 1L << 0, &keyboard_hook, &mlx);
	mlx_loop_hook(mlx.mlx, render_next_frame, &data);
    hook_events(&mlx);
	mlx_loop(mlx.mlx);
    
    return (0);
}
