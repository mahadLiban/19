/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyco.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:33:33 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 18:47:15 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_2(int keycode, t_screen *t_screen)
{
	if (keycode == 2 && ft_valid(keycode, t_screen))
	{
		t_screen->orient = 0;
		t_screen->x += 32;
		t_screen->count ++;
	}
}

void	ft_key_13(int keycode, t_screen *t_screen)
{
	if (keycode == 13 && ft_valid(keycode, t_screen))
	{
		if (t_screen->orient == 1)
		{
			t_screen->y -= 32;
			t_screen->count ++;
		}
		else
		{
			t_screen->y -= 32;
			t_screen->count ++;
		}
	}
}

void	ft_key_1(int keycode, t_screen *t_screen)
{
	if (keycode == 1 && ft_valid(keycode, t_screen))
	{
		if (t_screen->orient == 1)
		{
			t_screen->y += 32;
			t_screen->count ++;
		}
		else
		{
			t_screen->y += 32;
			t_screen->count ++;
		}
	}
}

void	ft_key_0(int keycode, t_screen *t_screen)
{
	if (keycode == 0 && ft_valid(keycode, t_screen))
	{
		t_screen->orient = 1;
		t_screen->x -= 32;
		t_screen->count ++;
	}
}

void	ft_protect_free(t_screen *t_screen, char *result)
{
	ft_protec(t_screen, result);
	free(result);
}
