/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:26:03 by lgracia-          #+#    #+#             */
/*   Updated: 2025/08/07 15:15:47 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(mlx_image_t *img, uint32_t ceiling, uint32_t floor)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < HEIGHT_WINDOW)
	{
		j = 0;
		while (j < WIDTH_WINDOW && i <= HEIGHT_WINDOW / 2)
			mlx_put_pixel(img, j++, i, ceiling);
		while (j < WIDTH_WINDOW && i > HEIGHT_WINDOW / 2)
			mlx_put_pixel(img, j++, i, floor);
		i++;
	}
}

int	parse_arg(int ac, char **av, t_cub *cub)
{
	int	fd;

	if (ac != 2)
		return (p_error("Wrong number of arguments\n"), 1);
	if (ft_file_extension(av[1], ".cub"))
		return (p_error("Wrong file extension\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (p_error("Unaccesible file\n"), 1);
	if (parse_file(fd, cub))
		return (close(fd), 1);
	close(fd);
	return (0);
}

static int	init_cub(t_cub *cub, int ac, char **av)
{
	if (parse_arg(ac, av, cub))
		return (1);
	cub->cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	cub->mlx = mlx_init(WIDTH_WINDOW, HEIGHT_WINDOW, "CUB", false);
	if (!cub->mlx)
		return (p_error("No window\n"), 1);
	return (0);
}

static int	init_images(t_cub *cub)
{
	if (convert_textures(cub))
		return (1);
	cub->img_background = mlx_new_image(cub->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	if (!cub->img_background)
		return (p_error("No image\n"), 1);
	draw_background(cub->img_background, cub->map->ceiling, cub->map->floor);
	if (mlx_image_to_window(cub->mlx, cub->img_background, 0, 0) < 0)
		return (1);
	cub->img = mlx_new_image(cub->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	if (!cub->img)
		return (p_error("No image\n"), 1);
	cast_ray(cub);
	if (mlx_image_to_window(cub->mlx, cub->img, 0, 0) < 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	if (init_cub(&cub, ac, av))
		return (clear_cub(&cub), 1);
	if (init_images(&cub))
		return (clear_cub(&cub), 1);
	if (minimap(&cub))
		return (clear_cub(&cub), 1);
	mlx_mouse_hook(cub.mlx, &mouse, &cub);
	mlx_key_hook(cub.mlx, &buttons, &cub);
	mlx_loop(cub.mlx);
	mlx_destroy_cursor(cub.cursor);
	clear_cub(&cub);
	return (0);
}
