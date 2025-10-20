/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:08:03 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/07 14:04:28 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_textures(t_texture *texture)
{
	if (texture->north)
		mlx_delete_texture(texture->north);
	if (texture->south)
		mlx_delete_texture(texture->south);
	if (texture->west)
		mlx_delete_texture(texture->west);
	if (texture->east)
		mlx_delete_texture(texture->east);
}

void	clear_t_textures(t_texture *texture, mlx_t *mlx)
{
	(void)mlx;
	clear_textures(texture);
	free(texture);
}

void	clear_img(t_cub *cub)
{
	if (cub->img)
		mlx_delete_image(cub->mlx, cub->img);
	if (cub->img_background)
		mlx_delete_image(cub->mlx, cub->img_background);
	if (cub->img_minimap)
		mlx_delete_image(cub->mlx, cub->img_minimap);
	if (cub->img_minimap_player)
		mlx_delete_image(cub->mlx, cub->img_minimap_player);
}

void	clear_cub(t_cub *cub)
{
	if (cub->map)
		clear_map(cub->map);
	if (cub->player)
		free(cub->player);
	if (cub->textures)
		clear_t_textures(cub->textures, cub->mlx);
	clear_img(cub);
}
