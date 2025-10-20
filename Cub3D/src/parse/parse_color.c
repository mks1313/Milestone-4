/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:16:17 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/08 19:10:29 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	is_color_acceptable_parse(char *line, size_t *j, size_t *i, \
	size_t *count)
{
	*j = 0;
	while (line[*i + *j] && line[*i + *j] != ',')
	{
		if (line[*i + *j] == '\n' || line[*i + *j] == '\0')
			break ;
		if (!ft_isdigit(line[*i + *j]))
			return (p_error("Color is not numeric character\n"), 1);
		if (*j >= 3)
			return (p_error("Num for color too wide\n"), 1);
		(*j)++;
	}
	if (++(*count) > 3)
		return (p_error("Too many values for rgb\n"), 1);
	return (0);
}

short	color_acceptable_to_int(char *line, size_t *i, size_t *j, size_t count)
{
	char		*tmp;

	tmp = ft_substr(line, *i, *j);
	*i += *j + (count < 3);
	while (line[*i] && ft_blank(line[*i]))
		(*i)++;
	*j = ft_atoi(tmp);
	free(tmp);
	if (*j > 255)
		return (p_error("Num for color is too wide\n"), 1);
	return (0);
}

short	is_color_acceptable(char *line, uint32_t *path, size_t *i)
{
	size_t			j;
	size_t			count;

	if (*path)
		return (p_error("Duplicated color type identifier"), 1);
	while (ft_blank(line[*i]))
		(*i)++;
	count = 0;
	while (line[*i])
	{
		if (is_color_acceptable_parse(line, &j, i, &count))
			return (1);
		if (color_acceptable_to_int(line, i, &j, count))
			return (1);
		if (count == 1)
			*path = (uint32_t)j;
		else
			*path = (uint32_t)((*path << 8) | j);
	}
	*path = (unsigned int)((*path << 8) | 255);
	return (0);
}

short	is_color(char *line, t_cub *cub, size_t *i)
{
	uint32_t	*path;

	if (line[*i] == 'C')
		path = &(cub->map->ceiling);
	else if (line[*i] == 'F')
		path = &(cub->map->floor);
	else
		return (0);
	(*i)++;
	if (is_color_acceptable(line, path, i))
		return (-1);
	return (1);
}
