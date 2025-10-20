/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:23:07 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/08 19:04:44 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	is_angle(char angle)
{
	if (angle == 'N')
		return (N);
	if (angle == 'S')
		return (S);
	if (angle == 'W')
		return (W);
	return (E);
}

short	parse_l_map(char *line, short *player_exist, size_t i)
{
	if (ft_strchrcmp(&line[i], "NWSE", 1))
	{
		(*player_exist)++;
		if (*player_exist > 1)
			return (p_error("More than one player set\n"), -1);
		if (*player_exist)
			return (1);
	}
	return (0);
}

short	parse_map_first_inloop(char *line, size_t l, size_t *w, t_cub *cub)
{
	static short	player_exist;
	short			ret;

	ret = parse_l_map(line, &player_exist, *w);
	if (ret == -1)
		return (free(line), 1);
	else if (ret == 1)
	{
		cub->player->angle = is_angle(line[*w]);
		cub->player->p_y = (double)l + 0.5;
		cub->player->p_x = (double)*w + 0.5;
	}
	if (!ft_blank(line[*w]) && (line)[*w] != '0' && (line)[*w] != '1' && !ret)
		return (p_error("Not acceptable character in map\n"), free(line), 1);
	(*w)++;
	return (0);
}

short	init_inloop(char *line, size_t *w, int *blank)
{
	*w = 0;
	while (ft_blank((line)[*w]))
		(*w)++;
	if (line && !line[*w])
		return (1);
	if ((int)*w < *blank)
		*blank = *w;
	return (0);
}
