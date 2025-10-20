/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:58:19 by lgracia-          #+#    #+#             */
/*   Updated: 2025/07/20 14:58:30 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*malloc_error(void *foo)
{
	if (!foo)
	{
		p_error("Malloc fail\n");
		exit(1);
	}
	return (foo);
}

void	p_error(char *msg)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(msg, 2);
}
