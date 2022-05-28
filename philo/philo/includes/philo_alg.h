/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:26:05 by mliban-s          #+#    #+#             */
/*   Updated: 2022/05/23 16:53:18 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ALG_H
# define PHILO_ALG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <time.h>
# include <sys/time.h>
# include <stdatomic.h>
# include <inttypes.h>

struct	s_philo;

typedef struct s_global
{
	atomic_bool			death;
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
	int					argc;
	int64_t				start_time;
	struct s_philo		*philos;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		mutex_print_me;
}			t_global;

typedef struct s_philo
{
	atomic_int				id;
	pthread_t				thread;
	t_global				*global;
	int						left_fork;
	int						right_fork;
	atomic_int_fast64_t		count_meal;
	atomic_int_fast64_t		last_lunch;
}			t_philo;

int				ft_parse(int argc, char **argv, t_global *global);
void			*routine(t_philo *philo);
void			ft_sleep(int64_t time);
int64_t			get_timestamp_in_ms(void);
void			write_routine(t_philo *philo, char *message);
void			ft_death(t_philo *philos, t_global	*global);
void			ft_init_philo(t_philo *philos, t_global *global);
void			ft_join_dest(t_philo *philos, t_global *global);
int				ft_init_fork(t_global *global);
void			ft_mix_func(t_philo *philos, t_global *global);
void			ft_mutex_fork(t_philo *philo);
void			ft_death(t_philo *philos, t_global *global);
void			ft_check_death(t_philo *philos, t_global *global);
#endif