/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:06:52 by nsoares-          #+#    #+#             */
/*   Updated: 2023/10/31 20:57:51 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# include <math.h>

# define SOUTH 0
# define NORTH 1
# define EAST 2
# define WEST 3


# define texWidth 64
# define texHeight 64
# define screenWidth 800
# define screenHeight 600

/* # define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124 */

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_texture
{
	int			t_w;
	int			t_h;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_texture;

typedef struct	s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
	struct s_data *data;
}				t_mlx;

typedef struct	s_data
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	double moveSpeed;
	double rotSpeed;
	double oldDirX;
	double oldPlaneX;
	int texX;
	int flag_up;
	int flag_down;
	int flag_left;
	int flag_right;
	int flag_rot_left;
	int flag_rot_right;

	t_mlx *mlx;
	struct s_map *map;
	t_texture *text;
}				t_data;


typedef struct	s_map
{
	char **worldMap; // armazenar o mapa
   /*  int mapWidth;
	int mapHeight; */
	double wallX;
	char *map_file;
	int fd;
	char *line;
	int nr_rows;
	char *n_texture;
	char *s_texture;
	char *w_texture;
	char *e_texture;
	char *floor_texture;
	char *ceiling_texture;
	double step;
	double texPos;
	t_data *data;
}				t_map;

// Mlx
void	mlx_exit(t_mlx *m);
int	hook_events(t_mlx *m);
void open_window(t_mlx *m);
int keyboard_hook(int keycode, t_mlx *m);
int keyboard_keyrelease(int keycode, t_mlx *m);

// Init
void init_all(t_mlx *m, t_data *data, t_map *map);
void init_textures(t_data *d);

// Parser
int		check_file(char *file);
int    check_args(int ac, char **av);
int check_file_extension(char *file_name);

// Map
void check_map(t_map *map);

// Draw
void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color);
int	my_mlx_pixel_get(t_texture *t, int x, int y);
void background(t_mlx *m);
int render_next_frame(void *param);

// Moves
void move_forward(t_data *d);
void move_backward(t_data *d);
void move_left(t_data *d);
void move_right(t_data *d);
void rotate_left(t_data *d);
void rotate_right(t_data *d);
void move_camera(t_data *d);

# endif