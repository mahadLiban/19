/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:04:18 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 22:12:05 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_deal_with_c(t_screen *t_screen, int i, int j, char *line)
{
	if (line[i] == 'C')
	{
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_conso, i * 32, j * 32);
		t_screen->numbers_of_collec++;
	}
}

void	ft_deal_with_zero(t_screen *t_screen, int i, int j, char *line)
{
	if (line[i] == '0')
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
}

void	ft_deal_with_one(t_screen *t_screen, int i, int j, char *line)
{
	if (line[i] == '1')
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_whole, i * 32, j * 32);
}

void	ft_deal_with_p(t_screen *t_screen, int i, int j, char *line)
{
	if (line[i] == 'P')
	{
		t_screen->x = i * 32;
		t_screen->y = j * 32;
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
	}
}

void	ft_deal_with_e(t_screen *t_screen, int i, int j, char *line)
{
	if (line[i] == 'E')
	{
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_floor, i * 32, j * 32);
		mlx_put_image_to_window(t_screen->mlx, t_screen->win,
			t_screen->img_end, i * 32, j * 32);
	}
	if (line[i] == '\n')
		return ;
	if (line[i] != 'C' && line[i] != 'P' && line[i] != '1'
		&& line[i] != '0' && line[i] != 'E')
		exit(1);
}
