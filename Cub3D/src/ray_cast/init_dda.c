/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:33:27 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 17:51:08 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dda_x(t_dda *dda, t_cub *cub)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (cub->player->p_x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - cub->player->p_x)
			* dda->delta_dist_x;
	}
}

static void	init_dda_y(t_dda *dda, t_cub *cub)
{
	if (dda->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (cub->player->p_y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - cub->player->p_y)
			* dda->delta_dist_y;
	}
}

void	init_dda(t_dda *dda, t_cub *cub, double ray_angle)
{
	dda->map_x = (int)cub->player->p_x;
	dda->map_y = (int)cub->player->p_y;
	dda->ray_dir_x = cos(ray_angle * M_PI / 180.0);
	dda->ray_dir_y = sin(ray_angle * M_PI / 180.0);
	dda->delta_dist_x = fabs(1.0 / dda->ray_dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->ray_dir_y);
	init_dda_x(dda, cub);
	init_dda_y(dda, cub);
}
