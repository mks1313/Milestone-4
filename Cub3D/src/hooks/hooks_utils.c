/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:19:51 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 18:59:15 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse(mouse_key_t key, action_t act, modifier_key_t mod, void *prm)
{
	t_cub	*cub;

	(void)mod;
	cub = (t_cub *)prm;
	if (key == MLX_MOUSE_BUTTON_LEFT && act == MLX_PRESS)
		mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_DISABLED);
	if (key == MLX_MOUSE_BUTTON_RIGHT && act == MLX_PRESS)
		mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_NORMAL);
}

int	is_walkable(t_cub *cub, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_x >= (int)cub->map->width \
			|| map_y >= (int)cub->map->length)
		return (0);
	if (cub->map->map[map_y][map_x] == '1')
		return (0);
	return (1);
}

void	move_player(t_cub *cub, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->p_x + move_x;
	new_y = cub->player->p_y + move_y;
	if (is_walkable(cub, new_x + PLAYER_RAD, cub->player->p_y) \
			&& is_walkable(cub, new_x - PLAYER_RAD, cub->player->p_y))
		cub->player->p_x = new_x;
	else
		printf("Colision horizontal\n");
	if (is_walkable(cub, cub->player->p_x, new_y + PLAYER_RAD) \
			&& is_walkable(cub, cub->player->p_x, new_y - PLAYER_RAD))
		cub->player->p_y = new_y;
	else
		printf("Colision vertical\n");
}
