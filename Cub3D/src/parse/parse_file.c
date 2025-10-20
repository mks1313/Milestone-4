/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:32:18 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/08 19:03:36 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

short	put_get_next_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (*line)
		return (1);
	return (0);
}

short	all_elements(t_map *map)
{
	if (map->floor == 0 || map->ceiling == 0)
		return (1);
	if (map->north == NULL || map->south == NULL)
		return (1);
	if (map->west == NULL || map->east == NULL)
		return (1);
	if (map->length == 0 || map->width == 0)
		return (1);
	if (map->map == NULL)
		return (1);
	return (0);
}

short	is_n_map(char *line, t_cub *cub, size_t *i)
{
	int	ret;

	ret = is_texture(line, cub, i);
	if (ret)
		return (ret);
	ret = is_color(line, cub, i);
	return (ret);
}

short	parse_file_is_line(char *line, size_t *i, int fd, t_cub *cub)
{
	short	ret;

	if (line && line[*i])
	{
		ret = is_n_map(line, cub, i);
		if (ret)
		{
			if (ret == -1)
				return (free(line), 1);
		}
		else if (line[*i] == '0' || line[*i] == '1')
		{
			if (parse_map(ft_strdup(line), fd, i, cub))
				return (free(line), 1);
		}
		else if (line[*i])
			return (p_error("Unreconized type identifier: "), \
			ft_putstr_fd(line, 2), free(line), 1);
	}
	return (0);
}

short	parse_file(int fd, t_cub *cub)
{
	char	*line;
	size_t	i;
	int		ret;

	cub->map = malloc_error(ft_calloc(sizeof(t_map), 1));
	cub->player = malloc_error(ft_calloc(sizeof(t_pov), 1));
	while (put_get_next_line(&line, fd) || all_elements(cub->map))
	{
		i = 0;
		if (!line)
			break ;
		while (ft_blank(line[i]))
			i++;
		ret = parse_file_is_line(line, &i, fd, cub);
		if (ret == 1)
			return (1);
		free(line);
	}
	if (all_elements(cub->map))
		return (p_error("Missing map elements\n"), 1);
	return (0);
}
	// *path = mlx_load_png(line);
	// if (!*path)
	// 	return (printf("%s\n", &line[i]), p_error("Unaccesible texture\n"), 1);
	// if (ft_file_extension(&line[i], ".xmp"))
	// 	xmp_to_mlx_texture(path);
	// else if (ft_file_extension(&line[i], ".png"))
	// 	mlx_load_png(path);
