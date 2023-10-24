/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:48:39 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/24 11:40:22 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_map(t_data *data)
{
    int x, y;

    for (y = 0; y < data->map_height; y++)
    {
        for (x = 0; x < data->map_width; x++)
        {
            int x_pos = x * data->tile_size;
            int y_pos = y * data->tile_size;

            // Exibe a textura na posição do mapa
            mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, x_pos, y_pos);
        }
    }
}

int render_next_frame(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
    return 0;
}

int main(int ac, char **av)
{
	//t_data	data;
	t_mlx	mlx;
	t_map	map;

	if (check_args(ac, av) == 1)
		exit(1);
	// inits
	// check / read map
	// open window
	// init textures
	// hook events
	// render next frame
	// mlx_loop

	puts("Enter in the game!");

	/* open_window(&mlx);
	init_mlx(&map);

	data.img = mlx_xpm_file_to_image(data.mlx, data.wall, &data.img_width, &data.img_height);
	//mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, data.x, data.y);

	for (int i = 0; i < data.map_height; i++)
    {
        data.map[i] = (int *)malloc(data.map_width * sizeof(int));
        for (int j = 0; j < data.map_width; j++)
        {
            data.map[i][j] = 0; // Valor de exemplo para o mapa
        }
    }

    // Desenhe o mapa com a textura
    draw_map(&data);

	
	//mlx_loop_hook(data.mlx, &render_next_frame, &data);
    hook_events(&data);
	mlx_loop(data.mlx); */
    
    return 0;
}
