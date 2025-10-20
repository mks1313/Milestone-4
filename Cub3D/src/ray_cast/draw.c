/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:54:17 by mmarinov          #+#    #+#             */
/*   Updated: 2025/08/07 17:11:52 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_pixel_info(mlx_texture_t *texture, int pixel_index)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = texture->pixels[pixel_index];
	g = texture->pixels[pixel_index + 1];
	b = texture->pixels[pixel_index + 2];
	a = texture->pixels[pixel_index + 3];
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw(t_cub *cub, mlx_texture_t *t, t_draw_dta *dta)
{
	unsigned int	pixel_index;
	uint32_t		tex_y;
	int				y;
	int				wall_top;
	int				wall_bottom;

	if (!cub->img || !cub->textures || !t || t->width <= 0 || t->height <= 0)
		return ;
	wall_top = (HEIGHT_WINDOW / 2) - (dta->wall_h / 2);
	wall_bottom = (HEIGHT_WINDOW / 2) + (dta->wall_h / 2);
	if (wall_top < 0)
		wall_top = 0;
	if (wall_bottom >= HEIGHT_WINDOW)
		wall_bottom = HEIGHT_WINDOW - 1;
	y = wall_top;
	while (y < wall_bottom)
	{
		tex_y = ((y - wall_top) * t->height) / dta->wall_h;
		pixel_index = (tex_y * t->width + dta->tex_x) * 4;
		mlx_put_pixel(cub->img, dta->x, y, get_pixel_info(t, pixel_index));
		y++;
	}
}
