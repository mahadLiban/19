/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:11:23 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 22:12:13 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_deal_with_c2(t_screen *t_screen, int i, int j)
{
	if (t_screen->map[j][i] == 'C')
	{
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_conso, i * 32, j * 32);
	}
}

void	ft_deal_with_zero2(t_screen *t_screen, int i, int j)
{
	if (t_screen->map[j][i] == '0')
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
}

void	ft_deal_with_one2(t_screen *t_screen, int i, int j)
{
	if (t_screen->map[j][i] == '1')
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_whole, i * 32, j * 32);
}

void	ft_deal_with_p2(t_screen *t_screen, int i, int j)
{
	if (t_screen->map[j][i] == 'P')
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
}

void	ft_deal_with_e2(t_screen *t_screen, int i, int j)
{
	if (t_screen->map[j][i] == 'E')
	{
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_end, i * 32, j * 32);
		if (t_screen->numbers_of_collec == 0)
		{
			mlx_put_image_to_window(t_screen->mlx, t_screen->win,
				t_screen->img_end_open, i * 32, j * 32);
		}
	}
}
