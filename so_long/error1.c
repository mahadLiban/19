/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:58:41 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 23:15:03 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_my_verificat(t_screen *t_screen)
{
	int	j;
	int	i;
	int	counts[4];

	j = 0;
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	while (t_screen->map[j])
	{
		i = 0;
		while (t_screen->map[j][i])
		{
			if (t_screen->map[j][i] == 'C')
				counts[0]++;
			if (t_screen->map[j][i] == 'P')
				counts[1]++;
			if (t_screen->map[j][i] == 'E')
				counts[2]++;
			i++;
		}
		j++;
	}
	if (counts[0] == 0 || counts[1] == 0 || counts[2] == 0)
		ft_mon_exit();
}

void	ft_wrong_map(int fd, char *result)
{
	if (fd < 0 || !result)
		exit(1);
}

int	ft_mon_exit(void)
{
	ft_printf("un item est manquant\n");
	exit(0);
}

void	ft_check_file(char **argv)
{
	int	x;

	x = ft_strlen(argv[1]) - 1;
	if ((argv[1][x] != 'r') || (argv[1][x - 1] != 'e')
		|| (argv[1][x - 2] != 'b') || (argv[1][x - 3] != '.'))
	{
		ft_printf("La map doit finir par .ber !\n");
		exit(EXIT_FAILURE);
	}
}

void	*free_strings(char **strings, t_dim t_dim)
{
	int	i;

	i = 0;
	while (i < t_dim.heigth)
	{
		free(strings[i]);
		i++;
	}
	free (strings);
	return (NULL);
}
