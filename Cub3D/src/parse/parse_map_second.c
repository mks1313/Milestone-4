/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:11:01 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/07 18:55:46 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	is_closed_map_corners(t_cub *cub, size_t x, size_t y)
{
	short	ret;

	ret = 0;
	if (cub->map->map[y + 1][x + 1] == '0')
		ret = (ret || is_closed_map(cub, x + 1, y + 1));
	if (!ret && cub->map->map[y + 1][x - 1] == '0')
		ret = (ret || is_closed_map(cub, x - 1, y + 1));
	if (!ret && cub->map->map[y - 1][x + 1] == '0')
		ret = (ret || is_closed_map(cub, x + 1, y - 1));
	if (!ret && cub->map->map[y - 1][x - 1] == '0')
		ret = (ret || is_closed_map(cub, x - 1, y - 1));
	return (ret);
}

short	is_closed_map(t_cub *cub, size_t x, size_t y)
{
	short	ret;

	ret = 0;
	if (cub->map->map[y][x] == '\0')
		return (1);
	if (cub->map->map[y][x] == '0')
	{
		if (!y || !x || y == cub->map->length - 1 || x == cub->map->width)
			return (1);
		cub->map->map[y][x] = '2';
		if (cub->map->map[y + 1][x] == '0')
			ret = (ret || is_closed_map(cub, x, y + 1));
		if (!ret && cub->map->map[y - 1][x] == '0')
			ret = (ret || is_closed_map(cub, x, y - 1));
		if (!ret && cub->map->map[y][x + 1] == '0')
			ret = (ret || is_closed_map(cub, x + 1, y));
		if (!ret && cub->map->map[y][x - 1] == '0')
			ret = (ret || is_closed_map(cub, x - 1, y));
		if (!ret)
			ret = is_closed_map_corners(cub, x, y);
	}
	return (ret);
}

char	**parse_map_second(char **tmp, t_cub *cub)
{
	t_map	*map;

	map = cub->map;
	map->map = malloc_error(ft_calloc(sizeof(char *), map->length + 1));
	if (!ft_arrayncpy_m(map->map, tmp, map->length + 1, map->blank))
		return (clear_array(tmp), p_error("Malloc fail\n"), NULL);
	clear_array(tmp);
	ft_arrayreplace(map->map, &ft_blank, '0');
	tmp = malloc_error(ft_calloc(sizeof(char *), map->length + 1));
	malloc_error(ft_arrayncpy_m(tmp, map->map, map->length, 0));
	map->map[(size_t)cub->player->p_y][(size_t)cub->player->p_x] = '0';
	if (is_closed_map(cub, cub->player->p_x, cub->player->p_y))
		return (p_error("Not closed map\n"), clear_array(tmp), NULL);
	clear_array(map->map);
	map->map = tmp;
	return (map->map);
}
