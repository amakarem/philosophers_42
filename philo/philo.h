/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:35:25 by aelaaser          #+#    #+#             */
/*   Updated: 2025/02/08 19:26:27 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>
# include <inttypes.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2
# define TAKE_FORKS "\033[1;34mhas taken a fork\033[0m"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "\033[1;32mis eating\033[0m"
# define DIED "\033[1;31mdied\033[0m"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}	t_philo;

typedef struct s_data
{
	int				philos_qty;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_loop;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
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

int			check_input(int argc, char **argv);
int			ft_atoi(const char *str);
void		print_instruction(void);
int			init_forks(t_data *data);
int			init_philos(t_data *data);
int			init_data(t_data *data, int argc, char **argv);
int			handle_1_philo(t_philo *philo);
bool		nb_meals_option(t_data *data);
void		free_data(t_data *data);
void		print_msg(t_data *data, int id, char *msg);
int			ft_atoi(const char *str);
void		wait_until(u_int64_t wakeup_time);
void		ft_usleep(uint64_t sleep_time);
u_int64_t	get_time(void);
bool		get_keep_loop(t_data *data);
int			get_philos_qty(t_data *data);
t_state		get_philo_state(t_philo *philo);
int			get_nb_meals_philo_had(t_philo *philo);
uint64_t	get_start_time(t_data *data);
uint64_t	get_die_time(t_data *data);
uint64_t	get_sleep_time(t_data *data);
uint64_t	get_eat_time(t_data *data);
uint64_t	get_last_eat_time(t_philo *philo);
void		update_last_meal_time(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_forks(t_philo *philo);
int			eat(t_philo *philo);
int			think(t_philo *philo);
int			ft_sleep(t_philo *philo);
void		set_keep_loop(t_data *data, bool set_to);
void		set_philo_state(t_philo *philo, t_state state);
bool		philo_died(t_philo *philo);
void		*all_full_routine(void *data_p);
void		*all_alive_routine(void *data_p);
int			philosophers(int argc, char **argv);

#endif