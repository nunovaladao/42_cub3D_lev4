/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:06:52 by nsoares-          #+#    #+#             */
/*   Updated: 2023/12/03 00:54:02 by nsoares-         ###   ########.fr       */
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

//# define MARGIN 0.5
# define TEXWIDTH 64
# define TEXTHEIGHT 64
# define SCREENWIDTH 800
# define SCREENHEIGHT 600

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_size_map
{
	int		lines;
	int		max_length;
}	t_size_map;

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

typedef struct s_mlx
{
	char			*addr;
	void			*img;
	void			*mlx;
	void			*mlx_win;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_data	*data;
}				t_mlx;

typedef struct s_data
{
	int				x;
	int				y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				tex_x;
	int				tex_y;
	double			dey;
	double			dex;
	double			rot;
	t_mlx			*mlx;
	struct s_map	*map;
	t_texture		*text;
}				t_data;

typedef struct s_map
{
	char	**worldmap;
	double	wall_x;
	double	step;
	double	tex_pos;
	char	*map_file;
	int		fd;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	t_data	*data;
	char	*color_c;
	char	*color_f;
	int		c_color;
	int		f_color;
}				t_map;

// Mlx
void	mlx_exit(t_mlx *m);
void	open_window(t_mlx *m);
int		keyboard_hook(int keycode, t_mlx *m);
int		keyboard_keyrelease(int keycode, t_mlx *m);

// Init
void	init_all(t_mlx *m, t_data *data, t_map *map);
void	init_textures(t_data *d);

// Parser
int		check_file(char *file, t_map *map);
int		check_args(int ac, char **av, t_map *map);
int		check_file_extension(char *file_name);
void	directions(t_data *data);
void	small_free(t_mlx *mlx, t_map *map);

// Draw
void	my_mlx_pixel_put(t_mlx *m, int x, int y, int color);
int		my_mlx_pixel_get(t_texture *t, int x, int y);
void	background(t_mlx *m);
int		render_next_frame(void *param);
void	calculations(t_data *d);
void	perform_dda(t_data *d);
void	draw_texture(t_data *d);
void	calc_wall_pixel(t_data *d);

// Moves
void	update_moves(t_data *data, double rot);

/*PARSER*/

/*Parser_init*/
int		check_text(char *test, t_map *map);
int		parse_gnl(t_map *map);
int		start_parser(t_map *map);

/*textures*/
int		save_value(char *test, t_map *map);
int		get_textures(char *test, t_map *map);
int		check_string(char *test, int *i);

/*Colors*/
int		get_factors_rgb(int *i, char *test);
void	get_hexa_parts(int *i, char **hexa, int color);
char	*get_hexa(t_rgb color);
int		get_colors(char *test, t_map *map);
int		clear_spaces(int *i, char *test, int a);

/*Map_part1*/
int		start_map(char *test, t_map *map);
int		check_characters(char *map_test);
char	**build_map(char *map_test, t_size_map	*s_map);
int		parse_map(char *map_test, t_map *map);

/*Map_part2*/
int		max_length_line(char *map_test);
int		number_of_lines(char *map_test);
char	*copy_map(char *map_test, int *j, int max_length);

/*map_floodfill*/
int		f_fill(char **map, t_size_map ms, int x, int y);
int		find_char(char **map, int *x, int *y, char find);
int		floodfill(char **map, t_size_map s_map);
int		f_fill_part2(char **map, t_size_map ms, int x, int y);

/*Error*/
void	free_map(t_map *map);
char	*cleaning_func_part2(char *test, t_map *map);
char	*cleaning_func_part3(char *map_test);
int		final_check_player(int a);

/*parser_part2*/
int		get_base_10(char *color);
char	*test_spaces(char *test);
char	*cleaning_func(char *test);

#endif
