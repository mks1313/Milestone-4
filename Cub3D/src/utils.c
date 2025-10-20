/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:04:13 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/07 15:26:55 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_arrayreplace(char **s, short (*f)(char), char c)
{
	size_t		i;
	size_t		j;

	if (!s || !f)
		return (NULL);
	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (f(s[j][i]))
				s[j][i] = c;
			i++;
		}
		j++;
	}
	return (s);
}

char	**ft_arrayncpy_m(char **dest, char **src, size_t n, size_t start)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = ft_strdup(&src[i][start]);
		if (!dest[i])
			return (clear_array(dest), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

short	ft_strchrcmp(char *s, char *c, int n)
{
	int	j;
	int	i;

	if (!s || !c)
		return (0);
	j = 0;
	while (c[j])
	{
		i = 0;
		while (s[i] && i < n)
		{
			if (s[i] == c[j])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

short	ft_blank(char c)
{
	if (c && (c == ' ' || c == '\n' || c == '\t'))
		return (1);
	return (0);
}

short	ft_file_extension(char *path, char *extension)
{
	int	l_extn;
	int	l_pextn;
	int	len;

	len = ft_strlen(path);
	l_extn = ft_strlen(extension);
	l_pextn = len - l_extn;
	if (l_pextn <= 0 || ft_strcmp(&path[l_pextn], extension))
		return (1);
	return (0);
}
