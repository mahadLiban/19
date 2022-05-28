/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:19:03 by mliban-s          #+#    #+#             */
/*   Updated: 2022/05/20 20:20:27 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_alg.h"

void	ft_mutex_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_forks[philo->left_fork]);
	write_routine(philo, "has taken a fork");
	pthread_mutex_lock(&philo->global->mutex_forks[philo->right_fork]);
	write_routine(philo, "has taken a fork");
}
