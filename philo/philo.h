/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:35:03 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 16:56:26 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <inttypes.h>

# define ERR_VALIDATION  1
# define ERR_ALLOC_PHILOS  2
# define ERR_ALLOC_FORKS   3
# define ERR_ALLOC_THREADS 4
# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DEAD 3
# define FULL 4
# define IDLE 5
# define MSN_TAKE_FORKS "has taken a fork"
# define MSN_THINK "is thinking"
# define MSN_SLEEP "is sleeping"
# define MSN_EAT "is eating"
# define MSN_DIED "died"

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	int				state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	uint64_t		last_eat_time;
}	t_philo;

typedef struct s_data
{
	int				philos_qty;
	int				nb_meals;
	int				nb_full_p;
	int				keep_loop;
	uint64_t		eat_time;
	uint64_t		die_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_philos_qty;
	pthread_mutex_t	mut_keep_loop;
	pthread_mutex_t	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_data;

int			ft_atoi(const char *str);
int			validinput(int argc, char **argv);
int			init_data(t_data *data, int argc, char **argv);
uint64_t	get_time(void);
void		ft_usleep(uint64_t sleep_time);
void		ft_wait(u_int64_t wakeup_time);
void		mutex_update_u64(pthread_mutex_t *mutex, uint64_t *target, uint64_t value);
uint64_t	mutex_get_u64(pthread_mutex_t *mutex, uint64_t *target);
int			mutex_get_int(pthread_mutex_t *mutex, int *target);
void		free_data(t_data *data);

#endif