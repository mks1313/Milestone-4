/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:53:45 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 18:10:24 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_ray_angle(t_cub *cub, int x)
{
	double	ray_angle;

	ray_angle = cub->player->angle - (FOV / 2) \
				+ ((double)x / WIDTH_WINDOW) * FOV;
	return (fmod(ray_angle, 360.0));
}

static mlx_texture_t	*get_texture(t_cub *cub, char hit_side)
{
	if (hit_side == 'N')
		return (cub->textures->north);
	else if (hit_side == 'S')
		return (cub->textures->south);
	else if (hit_side == 'E')
		return (cub->textures->east);
	else
		return (cub->textures->west);
}

static double	get_wall_x(t_cub *cub, double ray_ang, double dist, char hit_sd)
{
	if (hit_sd == 'E' || hit_sd == 'W')
		return (cub->player->p_y + dist * sin(ray_ang * M_PI / 180.0));
	else
		return (cub->player->p_x + dist * cos(ray_ang * M_PI / 180.0));
}

static void	draw_column(t_cub *cub, int x, double ray_angle)
{
	t_column_data	data;
	t_draw_dta		dta;
	mlx_texture_t	*texture;

	data.distance = find_wall_hit(cub, ray_angle, &data.hit_side);
	if (data.distance <= 0)
		return ;
	data.wall_height = (int)(HEIGHT_WINDOW / data.distance);
	texture = get_texture(cub, data.hit_side);
	data.wall_x = get_wall_x(cub, ray_angle, data.distance, data.hit_side);
	data.wall_x -= floor(data.wall_x);
	data.tex_x = (int)(data.wall_x * texture->width);
	if ((data.hit_side == 'E' && cos(ray_angle * M_PI / 180.0) < 0)
		|| (data.hit_side == 'S' && sin(ray_angle * M_PI / 180.0) > 0))
		data.tex_x = texture->width - data.tex_x - 1;
	dta.x = x;
	dta.wall_h = data.wall_height * 3;
	dta.tex_x = data.tex_x;
	draw(cub, texture, &dta);
}

void	cast_ray(t_cub *cub)
{
	int		x;
	double	ray_angle;

	draw_minimap_player(cub, cub->minimap_unit / 3,
		cub->img_minimap_player, 0x000000FF);
	draw_background(cub->img, cub->map->ceiling, cub->map->floor);
	x = 0;
	while (x < WIDTH_WINDOW)
	{
		ray_angle = calculate_ray_angle(cub, x);
		draw_column(cub, x, ray_angle);
		x++;
	}
}
