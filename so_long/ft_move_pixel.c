/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:34:51 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 23:15:38 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_pixels(int keycode, t_screen *t_screen)
{
	mlx_clear_window(t_screen->mlx, t_screen->win);
	ft_key_2(keycode, t_screen);
	ft_key_13(keycode, t_screen);
	ft_key_1(keycode, t_screen);
	ft_key_0(keycode, t_screen);
	if (keycode == 53)
		exit(0);
	if (t_screen->map[t_screen->y / 32][t_screen->x / 32] == 'C')
	{
		t_screen->map[t_screen->y / 32][t_screen->x / 32] = '0';
		t_screen->numbers_of_collec--;
		t_screen->count ++;
	}
	if (t_screen->map[t_screen->y / 32][t_screen->x / 32] == 'E'
		&& t_screen->numbers_of_collec == 0)
		exit(0);
	ft_my_map2(t_screen);
	if (t_screen->orient == 1)
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_rev, t_screen->x, t_screen->y);
	else
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img, t_screen->x, t_screen->y);
	display_count(t_screen);
	return (0);
}

void	display_count(t_screen *t_screen)
{
	char	*string;

	string = ft_itoa(t_screen->count);
	if (!string)
		exit(1);
	mlx_string_put(t_screen->mlx, t_screen->win, 0, 0, 0xFF3333, string);
	free(string);
}
