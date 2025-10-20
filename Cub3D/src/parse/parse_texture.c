/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:09:58 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/08 19:06:56 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*mlx_texture_dup(mlx_texture_t texture)
{
	mlx_texture_t	*new;

	new = malloc_error(ft_calloc(sizeof(mlx_texture_t), 1));
	new->width = texture.width;
	new->height = texture.height;
	new->bytes_per_pixel = texture.bytes_per_pixel;
	new->pixels = texture.pixels;
	return (new);
}

short	convert_textures_extension(char *path, mlx_texture_t **texture)
{
	xpm_t	*xmp;

	if (!ft_file_extension(path, ".xmp\n"))
	{
		xmp = mlx_load_xpm42(path);
		if (!xmp)
		{
			p_error("Unable to convert textures");
			ft_putstr_fd(path, 2);
			return (1);
		}
		*texture = mlx_texture_dup(xmp->texture);
		mlx_delete_xpm42(xmp);
	}
	else
	{
		*texture = mlx_load_png(path);
		if (!*texture)
		{
			p_error("Unable to convert texture: ");
			ft_putstr_fd(path, 2);
			return (1);
		}
	}
	return (0);
}

short	convert_textures(t_cub *cub)
{
	cub->textures = malloc_error(ft_calloc(sizeof(t_texture), 1));
	if (convert_textures_extension(cub->map->north, &cub->textures->north))
		return (1);
	if (convert_textures_extension(cub->map->south, &cub->textures->south))
		return (1);
	if (convert_textures_extension(cub->map->west, &cub->textures->west))
		return (1);
	if (convert_textures_extension(cub->map->east, &cub->textures->east))
		return (1);
	cub->textures->img_n = mlx_texture_to_image(cub->mlx, cub->textures->north);
	cub->textures->img_s = mlx_texture_to_image(cub->mlx, cub->textures->south);
	if (!cub->textures->img_n || !cub->textures->img_s)
		return (p_error("Unable to convert texture to image\n"), 1);
	cub->textures->img_w = mlx_texture_to_image(cub->mlx, cub->textures->west);
	cub->textures->img_e = mlx_texture_to_image(cub->mlx, cub->textures->east);
	if (!cub->textures->img_w || !cub->textures->img_e)
		return (p_error("Unable to convert texture to image\n"), 1);
	return (0);
}

short	is_texture_acceptable(char *line, char **path, size_t i)
{
	size_t	len;
	int		iter;
	int		path_len;

	if (*path)
		return (p_error("Duplicated texture type identifier"), 1);
	while (ft_blank(line[i]))
		i++;
	if (!line[i])
		return (p_error("No texture path found\n"), 1);
	if (!ft_file_extension(&line[i], ".xmp\n") \
			&& !ft_file_extension(&line[i], ".png\n"))
		return (p_error("Not acceptable texture extension\n"), 1);
	len = 0;
	while (!ft_blank(line[i + len]) && line[i + len] != '\n' && \
	line[i + len] != '\0')
		len++;
	iter = 0;
	path_len = ft_strlen(&line[i]) - 2;
	while (iter < path_len && !ft_blank((&(line)[i])[iter]))
		iter++;
	if (ft_blank((&(line)[i])[iter]))
		return (p_error("Spaces in texture: "), printf("%s", &line[i]), 1);
	*path = malloc_error(ft_substr(line, i, len));
	return (0);
}

short	is_texture(char *line, t_cub *cub, size_t *i)
{
	char	**path;

	if (line[*i] == 'N' && line[*i + 1] && line[*i + 1] == 'O')
		path = &cub->map->north;
	else if (line[*i] == 'S' && line[*i + 1] && line[*i + 1] == 'O')
		path = &cub->map->south;
	else if (line[*i] == 'W' && line[*i + 1] && line[*i + 1] == 'E')
		path = &cub->map->west;
	else if (line[*i] == 'E' && line[*i + 1] && line[*i + 1] == 'A')
		path = &cub->map->east;
	else
		return (0);
	*i += 2;
	if (is_texture_acceptable(line, path, *i))
		return (-1);
	*i = ft_strlen(line);
	return (1);
}
