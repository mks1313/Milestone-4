/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:43:43 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/08 19:05:24 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_ended(size_t l, t_cub *cub)
{
	cub->map->width -= cub->map->blank;
	cub->map->length = l;
	cub->player->p_x -= cub->map->blank;
}

static int	process_map_line(char **line, t_parse_map *tmp,
				t_cub *cub, size_t *w)
{
	if (tmp->l >= MAX_MAP)
		return (free(*line), clear_array(tmp->map), printf("Max map\n"), -1);
	if (init_inloop(*line, w, &cub->map->blank))
	{
		free(*line);
		return (1);
	}
	while ((*line)[*w] && (*line)[*w] != '\n')
	{
		if (*w >= MAX_MAP)
			return (free(*line), clear_array(tmp->map), \
				printf("Max map\n"), -1);
		if (parse_map_first_inloop(*line, tmp->l, w, cub))
			return (free(*line), clear_array(tmp->map), -1);
	}
	if (*w > cub->map->width)
		cub->map->width = *w;
	tmp->map[(tmp->l)++] = *line;
	return (0);
}

char	**parse_map_first_loop(char **line, int fd, size_t *w, t_cub *cub)
{
	t_parse_map	tmp;
	int			status;

	tmp.l = 0;
	cub->map->blank = INT_MAX;
	tmp.map = malloc_error(ft_calloc(sizeof(char *), MAX_MAP));
	while (*line)
	{
		status = process_map_line(line, &tmp, cub, w);
		if (status == 1)
			break ;
		else if (status == -1)
			return (NULL);
		*line = get_next_line(fd);
	}
	if (!cub->player->p_y)
		return (p_error("No player found till next empty line in map\n"),
			clear_array(tmp.map), NULL);
	loop_ended(tmp.l, cub);
	return (tmp.map);
}

char	**parse_map_first(char *line, int fd, size_t *w, t_cub *cub)
{
	char		**map;

	map = parse_map_first_loop(&line, fd, w, cub);
	if (!map)
		return (NULL);
	free(cub->map->map);
	return (map);
}

short	parse_map(char *line, int fd, size_t *w, t_cub *cub)
{
	char	**tmp;

	if (cub->map->width)
		return (free(line), p_error("Duplicated map or divided map\n"), 1);
	tmp = parse_map_first(line, fd, w, cub);
	if (!tmp)
		return (1);
	if (!parse_map_second(tmp, cub))
		return (1);
	return (0);
}
