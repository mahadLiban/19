/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:19:49 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 22:12:20 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_win_size(t_screen *t_screen, char *argv)
{
	int		fd;
	char	*line;
	int		y;
	int		x;

	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		free(line);
		x = 0;
		while (line[x] && line[x] != '\n')
			x++;
		line = get_next_line(fd);
		y++;
	}
	t_screen->win = mlx_new_window(t_screen->mlx, x * 32, y * 32, "so_long");
	return (0);
}

int	ft_valid(int keycode, t_screen *t_screen)
{
	if (keycode == 2 && t_screen->map[t_screen->y / 32]
		[(t_screen->x + 32) / 32] != '1')
		return (1);
	if (keycode == 13 && t_screen->map[(t_screen->y - 32) / 32]
		[(t_screen->x) / 32] != '1')
		return (1);
	if (keycode == 1 && t_screen->map[(t_screen->y + 32) / 32]
		[(t_screen->x) / 32] != '1')
		return (1);
	if (keycode == 0 && t_screen->map[t_screen->y / 32]
		[(t_screen->x - 32) / 32] != '1')
		return (1);
	return (0);
}

int	ft_clean_win(t_screen *t_screen)
{
	mlx_destroy_window(t_screen->mlx, t_screen->win);
	exit(0);
	return (0);
}

int	init_img(t_screen *display, int width, int height)
{
	display->img = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/monbeausonic.xpm", &width, &height);
	display->img_rev = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/monrevers.xpm", &width, &height);
	display->img_end = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/portail_rouge.xpm", &width, &height);
	display->img_end_open = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/portail_vert.xpm", &width, &height);
	display->img_conso = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/rings.xpm", &width, &height);
	display->img_floor = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/mur.xpm", &width, &height);
	display->img_whole = mlx_xpm_file_to_image(display->mlx,
			"./mesXpm/sol.xpm", &width, &height);
	return (0);
}

int	main(int argc, char **argv)
{
	t_screen	display;
	int			width;
	int			height;

	width = 0;
	height = 0;
	if (argc != 2)
		return (0);
	display.count = 0;
	display.actif = 1;
	ft_check_file(argv);
	display.mlx = mlx_init();
	init_img(&display, width, height);
	ft_win_size(&display, argv[1]);
	ft_my_map(&display, argv[1]);
	mlx_put_image_to_window(display.mlx, display.win,
		display.img, display.x, display.y);
	mlx_key_hook(display.win, ft_move_pixels, &display);
	mlx_hook(display.win, 17, 0, ft_clean_win, &display);
	mlx_loop(display.mlx);
	return (0);
}
