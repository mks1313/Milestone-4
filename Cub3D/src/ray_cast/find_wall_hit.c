/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:15:07 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 17:46:24 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	advance_dda_step(t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->map_x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->map_y += dda->step_y;
		dda->side = 1;
	}
}

static int	check_wall_hit(t_cub *cub, t_dda *dda, double *dist)
{
	if (dda->map_x < 0 || (size_t)dda->map_x >= cub->map->width
		|| dda->map_y < 0 || (size_t)dda->map_y >= cub->map->length)
		return (-1);
	if (cub->map->map[dda->map_y][dda->map_x] == '1')
	{
		if (dda->side == 0)
			*dist = (dda->map_x - cub->player->p_x + (1 - dda->step_x) / 2.0)
				/ dda->ray_dir_x;
		else
			*dist = (dda->map_y - cub->player->p_y + (1 - dda->step_y) / 2.0)
				/ dda->ray_dir_y;
		return (1);
	}
	return (0);
}

static void	set_hit_side(t_dda *dda, char *hit_side)
{
	if (dda->side == 0)
	{
		if (dda->step_x < 0)
			*hit_side = 'W';
		else
			*hit_side = 'E';
	}
	else
	{
		if (dda->step_y < 0)
			*hit_side = 'N';
		else
			*hit_side = 'S';
	}
}

static double	dda_loop(t_dda *dda, t_cub *cub)
{
	int		steps;
	double	dist;
	int		hit;

	steps = 0;
	while (++steps < MAX_MAP)
	{
		advance_dda_step(dda);
		hit = check_wall_hit(cub, dda, &dist);
		if (hit == 1)
			return (dist);
		else if (hit == -1)
			return (-1);
	}
	return (-1);
}

double	find_wall_hit(t_cub *cub, double ray_angle, char *hit_side)
{
	t_dda	dda;
	double	dist;

	init_dda(&dda, cub, ray_angle);
	dist = dda_loop(&dda, cub);
	if (dist == -1)
		return (-1);
	set_hit_side(&dda, hit_side);
	return (dist);
}
