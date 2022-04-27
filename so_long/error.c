/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:34:25 by mliban-s          #+#    #+#             */
/*   Updated: 2022/03/29 14:07:38 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_dim	ft_heigth_width(t_screen *t_screen)
{
	t_dim	dim;
	int		i;

	i = 0;
	dim.heigth = 0;
	while (t_screen->map[i])
	{
		dim.heigth++;
		dim.width = 0;
		while (t_screen->map[0][dim.width])
			dim.width++;
		i++;
	}
	return (dim);
}

int	ft_top_x(t_screen *t_screen)
{
	int	i;

	i = 0;
	while (t_screen->map[0][i])
	{
		if (t_screen->map[0][i] != '1')
		{
			ft_printf("on a dit des 1");
			exit(0);
		}
		i++;
	}
	return (0);
}

int	ft_left_y(t_screen *t_screen)
{
	int	j;

	j = 0;
	while (t_screen->map[j])
	{
		if (t_screen->map[j][0] != '1')
		{
			ft_printf("on a dit des 1");
			exit(0);
		}
		j++;
	}
	return (0);
}

int	ft_right_y(t_screen *t_screen)
{
	t_dim	last;
	int		i;

	last = ft_heigth_width(t_screen);
	i = 0;
	while (i < last.heigth)
	{
		if (t_screen->map[i][last.width - 1] != '1')
		{
			ft_printf("on a dit des 1 ICI\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

int	ft_bottom_x(t_screen *t_screen)
{
	t_dim	last;
	int		i;

	last = ft_heigth_width(t_screen);
	i = 0;
	while (i < last.width)
	{
		if (t_screen->map[last.heigth - 1][i] != '1')
		{
			ft_printf("on a dit des 1\n");
			exit(0);
		}
		i++;
	}
	return (0);
}
