/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:52:09 by mliban-s          #+#    #+#             */
/*   Updated: 2022/05/23 16:36:32 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_alg.h"

int64_t	get_timestamp_in_ms(void)
{
	struct timeval	time;
	int64_t			timestamp_in_ms;

	gettimeofday(&time, NULL);
	timestamp_in_ms = (time.tv_sec * 1000) + (time.tv_usec) / 1000;
	return (timestamp_in_ms);
}

void	ft_sleep(int64_t time)
{
	int64_t	now;
	int64_t	start;

	start = get_timestamp_in_ms();
	while (true)
	{
		now = get_timestamp_in_ms();
		if (now - start >= time)
			break ;
		usleep(50);
	}
}

void	ft_init_philo(t_philo *philos, t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		philos[i].count_meal = 0;
		philos[i].id = i;
		philos[i].global = global;
		philos[i].left_fork = i;
		philos[i].right_fork = (i + 1) % global->nb_philo;
		philos[i].last_lunch = get_timestamp_in_ms();
		pthread_create(&philos[i].thread, NULL,
			(void *)routine, &philos[i]);
		i++;
	}
}
