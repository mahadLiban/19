/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:36:39 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 22:12:49 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parse_map(t_screen *t_screen, int i, int j, char *line)
{
	ft_deal_with_c(t_screen, i, j, line);
	ft_deal_with_zero(t_screen, i, j, line);
	ft_deal_with_one(t_screen, i, j, line);
	ft_deal_with_p(t_screen, i, j, line);
	ft_deal_with_e(t_screen, i, j, line);
}

void	ft_parse_map2(t_screen *t_screen, int i, int j)
{
	ft_deal_with_c2(t_screen, i, j);
	ft_deal_with_zero2(t_screen, i, j);
	ft_deal_with_one2(t_screen, i, j);
	ft_deal_with_p2(t_screen, i, j);
	ft_deal_with_e2(t_screen, i, j);
}

void	ft_my_map(t_screen *t_screen, char *argv)
{
	int		fd;
	char	*line;
	char	*result;
	int		j;
	int		i;

	fd = open(argv, O_RDONLY);
	result = ft_calloc(1, sizeof(char));
	ft_wrong_map(fd, result);
	line = get_next_line(fd);
	j = -1;
	if (line == 0)
		exit(1);
	while (line && ++j >= 0)
	{
		i = -1;
		while (line[++i])
			ft_parse_map(t_screen, i, j, line);
		if (line[0] == '\n')
			exit(1);
		result = ft_strjoin(result, line);
		free(line);
		line = get_next_line(fd);
	}
	ft_protect_free(t_screen, result);
}

void	ft_protec(t_screen *t_screen, char *result)
{
	t_screen->map = ft_split(result, '\n');
	ft_left_y(t_screen);
	ft_right_y(t_screen);
	ft_top_x(t_screen);
	ft_bottom_x(t_screen);
	ft_my_verificat(t_screen);
}

int	ft_my_map2(t_screen *t_screen)
{
	int	j;
	int	i;

	j = 0;
	while (t_screen->map[j])
	{
		i = 0;
		while (t_screen->map[j][i])
		{
			ft_parse_map2(t_screen, i, j);
			i++;
		}
		j++;
	}
	return (0);
}
