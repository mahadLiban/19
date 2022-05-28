/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:00:34 by mliban-s          #+#    #+#             */
/*   Updated: 2022/05/23 16:55:35 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_alg.h"

void	ft_death(t_philo *philos, t_global	*global)
{
	int	i;

	i = 0;
	while (global->death != true)
	{
		if ((int)(get_timestamp_in_ms() - philos[i].last_lunch)
			> global->time_to_die)
		{
			pthread_mutex_lock(&global->mutex_print_me);
			global->death = true;
			printf("%"PRId64 " %d is dead\n", get_timestamp_in_ms()
				- global->start_time, global->philos[i].id);
			pthread_mutex_unlock(&global->mutex_print_me);
		}
		i++;
		if (i == global->nb_philo)
			i = 0;
		if (global->argc == 6)
			ft_check_death(philos, global);
	}
}

void	ft_check_death(t_philo *philos, t_global *global)
{
	int	i;

	i = 0;
	if (global->nb_eat < philos->count_meal)
	{
		global->death = true;
	}
	i++;
}

void	ft_join_dest(t_philo *philos, t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		philos[i].id = i;
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&global->mutex_forks[i]);
		i++;
	}
}

int	ft_init_fork(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->nb_philo)
	{
		if (pthread_mutex_init(&global->mutex_forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_mix_func(t_philo *philos, t_global *global)
{
	ft_init_fork(global);
	ft_init_philo(philos, global);
	ft_death(philos, global);
	ft_join_dest(philos, global);
}
