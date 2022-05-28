/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:33:28 by mliban-s          #+#    #+#             */
/*   Updated: 2022/05/23 16:47:56 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_alg.h"

void	write_routine(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->global->mutex_print_me);
	if (philo->global->death != true)
		printf("%"PRId64 " %d %s\n", get_timestamp_in_ms()
			-philo->global->start_time, philo->id, message);
	pthread_mutex_unlock(&philo->global->mutex_print_me);
}

void	*routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(philo->global->time_to_eat / 2);
	ft_sleep(philo->global->time_to_eat);
	while (philo->global->death != true)
	{
		if (philo->id % 2)
			ft_mutex_fork(philo);
		else
		{
			pthread_mutex_lock(&philo->global->mutex_forks[philo->right_fork]);
			write_routine(philo, "has taken a fork");
			pthread_mutex_lock(&philo->global->mutex_forks[philo->left_fork]);
			write_routine(philo, "has taken a fork");
		}
		write_routine(philo, "is eating");
		philo->count_meal++;
		philo->last_lunch = get_timestamp_in_ms();
		ft_sleep(philo->global->time_to_eat);
		pthread_mutex_unlock(&philo->global->mutex_forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->global->mutex_forks[philo->left_fork]);
		write_routine(philo, "is sleeping");
		ft_sleep(philo->global->time_to_sleep);
		write_routine(philo, "is thinking");
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_global	global;
	int			i;

	if (ft_parse(argc, argv, &global) == 1)
	{
		printf("Arg not valid\n");
		return (0);
	}
	global.argc = argc;
	i = 0;
	if (pthread_mutex_init(&global.mutex_print_me, NULL) != 0)
		return (0);
	global.death = false;
	philos = malloc(sizeof(t_philo) * global.nb_philo);
	if (!philos)
		return (0);
	global.philos = philos;
	global.start_time = get_timestamp_in_ms();
	global.mutex_forks = malloc(sizeof(pthread_mutex_t) * global.nb_philo);
	if (!global.mutex_forks)
		return (0);
	ft_mix_func(philos, &global);
	return (0);
}
