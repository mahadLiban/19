/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:23:24 by mliban-s          #+#    #+#             */
/*   Updated: 2022/05/23 16:55:24 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_alg.h"

static bool	ft_atoi_none_nega(const char *str, int *nb)
{
	unsigned int	result;

	result = 0;
	if (!*str)
		return (true);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result > INT_MAX)
			return (true);
	}
	if (*str)
		return (true);
	if (nb)
		*nb = result;
	return (false);
}

int	ft_parse(int argc, char **argv, t_global *global )
{
	if (argc != 5 && argc != 6)
		return (1);
	if (ft_atoi_none_nega(argv[1], &global->nb_philo))
		return (1);
	if (ft_atoi_none_nega(argv[2], (int *) &global->time_to_die))
		return (1);
	if (ft_atoi_none_nega(argv[3], &global->time_to_eat))
		return (1);
	if (ft_atoi_none_nega(argv[4], &global->time_to_sleep))
		return (1);
	if (argc == 6 && (ft_atoi_none_nega(argv[5], &global->nb_eat)))
		return (1);
	return (0);
}
