/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:24:59 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 13:13:44 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_player(t_cub *cub, int r, mlx_image_t *img, \
	unsigned int color)
{
	float	i;
	int		x;
	int		y;
	int		xc;
	int		yc;

	xc = cub->player->p_x * cub->minimap_unit;
	yc = cub->player->p_y * cub->minimap_unit;
	while (r--)
	{
		if (color && r == r - r / 5)
			color = 0xFFFFFFFF;
		i = 0;
		while (i < 360)
		{
			x = (r * sin(i)) + xc;
			y = (r * cos(i)) + yc;
			mlx_put_pixel(img, x, y, color);
			i += 0.01;
		}
	}
}

void	draw_sq(t_cub *cub, int unit, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i <= unit)
	{
		j = 0;
		while (j <= unit)
		{
			mlx_put_pixel(cub->img_minimap, x + j, y + i, 0xAAAAAAAA);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_cub *cub, int unit)
{
	int			i;
	int			j;
	int			iu;

	i = 0;
	iu = 0;
	while (cub->map->map[i])
	{
		j = 0;
		while (cub->map->map[i][j])
		{
			if (cub->map->map[i][j] == '1')
				draw_sq(cub, unit, j * unit, i * unit);
			j++;
		}
		i++;
	}
}

void	get_minimap_unit(t_cub *cub)
{
	int	minimap_max;

	if (cub->map->width > cub->map->length)
	{
		minimap_max = WIDTH_WINDOW / 3;
		cub->minimap_unit = minimap_max / cub->map->width;
	}
	else
	{
		minimap_max = HEIGHT_WINDOW / 3;
		cub->minimap_unit = minimap_max / cub->map->length;
	}
}

int	minimap(t_cub *cub)
{
	get_minimap_unit(cub);
	cub->img_minimap = mlx_new_image(cub->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	cub->img_minimap_player = \
	mlx_new_image(cub->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	if (!cub->img_minimap || !cub->img_minimap_player)
		return (p_error("No minimap image\n"), 1);
	draw_minimap(cub, cub->minimap_unit);
	draw_minimap_player(cub, cub->minimap_unit / 3, cub->img_minimap_player, \
		0x000000FF);
	if (mlx_image_to_window(cub->mlx, cub->img_minimap, 0, 0) < 0)
		return (p_error("Unable to display minimap image\n"), 1);
	if (mlx_image_to_window(cub->mlx, cub->img_minimap_player, 0, 0) < 0)
		return (p_error("Unable to display minimap player image\n"), 1);
	return (0);
}
