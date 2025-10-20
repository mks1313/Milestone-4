/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:07:58 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/10 10:45:30 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/MLX42_Int.h"
# include "libft/includes/libft.h"

# define WIDTH_WINDOW	1920
# define HEIGHT_WINDOW	1080
# define PLAYER_RAD	0.2
# define FOV				30	// usual FOV is 60
# define ROTATION_STEP	5// total is 360º, add/take nº when rotate
# define MOVE_STEP		0.2
# define N				270
# define S				90
# define W				180
# define E				0
# define ERROR			"\033[91;5mError\n\033[0m"
# define MAX_MAP			1000
# define COLLISION_THRESHOLD 0.5

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
}				t_dda;

typedef struct s_draw_dta
{
	int	x;
	int	wall_h;
	int	tex_x;
}				t_draw_dta;

typedef struct s_column_data
{
	double	distance;
	char	hit_side;
	int		wall_height;
	double	wall_x;
	int		tex_x;
}				t_column_data;

typedef struct s_parse_map
{
	char	**map;
	size_t	l;
}				t_parse_map;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	mlx_image_t		*img_n;
	mlx_image_t		*img_s;
	mlx_image_t		*img_w;
	mlx_image_t		*img_e;
}				t_texture;

typedef struct s_map
{
	uint32_t		floor;
	uint32_t		ceiling;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	size_t			length;
	size_t			width;
	int				blank;
	char			**map;
}				t_map;

typedef struct s_pov
{
	double	p_x;
	double	p_y;
	short	angle;
}				t_pov;

typedef struct s_cub
{
	mlx_t				*mlx;
	mlx_image_t			*img_background;
	mlx_image_t			*img_minimap;
	mlx_image_t			*img_minimap_player;
	mlx_image_t			*img;
	t_map				*map;
	t_texture			*textures;
	t_pov				*player;
	int					minimap_unit;
	mlx_win_cursor_t	*cursor;
}				t_cub;

/*	parse/parse_file.c*/
short		parse_file(int fd, t_cub *cub);
/*	parse/parse_color.c*/
short		is_color(char *line, t_cub *cub, size_t *i);
/*	parse/parse_texture.c*/
short		convert_textures(t_cub *cub);
short		is_texture(char *line, t_cub *cub, size_t *i);
/*	parse/parse_map.c*/
short		parse_map(char *line, int fd, size_t *i, t_cub *cub);
/*	parse_parse_map_first.c*/
short		init_inloop(char *line, size_t *w, int *blank);
short		parse_map_first_inloop(char *line, size_t l, size_t *w, t_cub *cub);

/*	parse/parse_map_second.c*/
short		is_closed_map(t_cub *cub, size_t x, size_t y);
char		**parse_map_second(char **tmp, t_cub *cub);

/*	hooks/hooks.c*/
void		mouse(mouse_key_t key, action_t act, modifier_key_t mod, void *prm);
void		buttons(mlx_key_data_t keydata, void *param);
void		move_player(t_cub *cub, double move_x, double move_y);

/*	utils.c*/
char		**ft_arrayreplace(char **s, short (*f)(char), char c);
char		**ft_arrayncpy_m(char **dest, char **src, size_t n, size_t start);
short		ft_strchrcmp(char *s, char *c, int n);
short		ft_blank(char c);
short		ft_file_extension(char *path, char *extension);

/* error.c*/
void		*malloc_error(void *foo);
void		p_error(char *msg);

/*	clear/clear.c*/
void		clear_t_textures(t_texture *texture, mlx_t *mlx);
void		clear_array(char **array);
void		clear_map(t_map *map);
void		clear_cub(t_cub *cub);

/*Ray_cast*/
uint32_t	get_pixel_info(mlx_texture_t *texture, int pixel_index);
void		draw(t_cub *cub, mlx_texture_t *t, t_draw_dta *dta);
double		calculate_ray_angle(t_cub *cub, int x);
double		find_wall_hit(t_cub *cub, double ray_angle, char *hit_side);
void		cast_ray(t_cub *cub);
void		draw_background(mlx_image_t *img, uint32_t ceiling, uint32_t floor);
int			minimap(t_cub *cub);
void		draw_minimap_player(t_cub *cub, int r, mlx_image_t *img, \
	unsigned int color);
void		init_dda(t_dda *dda, t_cub *cub, double ray_angle);

#endif
