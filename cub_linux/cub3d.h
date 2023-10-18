/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:06:52 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/18 20:47:12 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define ESC 65307
# define D_KEY 100
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define ARROW_RIGHT_KEY 65363
# define ARROW_LEFT_KEY 65361

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
}				t_data;

void	mlx_exit(t_data *data);
int	hook_events(t_data *data);


# endif