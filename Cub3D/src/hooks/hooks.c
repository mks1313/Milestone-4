/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:37:25 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 13:59:09 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	toggle_minimap(t_cub *cub)
{
	bool	state;

	state = cub->img_minimap_player->instances->enabled;
	cub->img_minimap_player->instances->enabled = !state;
	cub->img_minimap->instances->enabled = !state;
}

void	get_mov_dir(t_cub *cub, mlx_key_data_t key, double *m_x, double *m_y)
{
	double	angle;

	angle = cub->player->angle * (M_PI / 180);
	*m_x = 0;
	*m_y = 0;
	if (key.key == MLX_KEY_W)
	{
		*m_x = cos(angle);
		*m_y = sin(angle);
	}
	else if (key.key == MLX_KEY_S)
	{
		*m_x = -cos(angle);
		*m_y = -sin(angle);
	}
	else if (key.key == MLX_KEY_A)
	{
		*m_x = sin(angle);
		*m_y = -cos(angle);
	}
	else if (key.key == MLX_KEY_D)
	{
		*m_x = -sin(angle);
		*m_y = cos(angle);
	}
}

void	handle_move(t_cub *cub, mlx_key_data_t key)
{
	double	move_x;
	double	move_y;

	get_mov_dir(cub, key, &move_x, &move_y);
	move_x *= MOVE_STEP;
	move_y *= MOVE_STEP;
	move_player(cub, move_x, move_y);
}

static void	handle_rotation(t_cub *cub, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_RIGHT)
	{
		cub->player->angle += ROTATION_STEP;
		if (cub->player->angle >= 360)
			cub->player->angle -= 360;
	}
	else if (key.key == MLX_KEY_LEFT)
	{
		cub->player->angle -= ROTATION_STEP;
		if (cub->player->angle < 0)
			cub->player->angle += 360;
	}
}

void	buttons(mlx_key_data_t keydata, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	draw_minimap_player(cub, cub->minimap_unit \
			/ 3, cub->img_minimap_player, 0x00000000);
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		toggle_minimap(cub);
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		handle_move(cub, keydata);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT)
		handle_rotation(cub, keydata);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(cub->mlx);
	cast_ray(cub);
}
