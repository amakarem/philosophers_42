/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:56:47 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 19:38:13 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	assign_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	philos = data->philos;
	i = -1;
	while (++i < data->philos_qty)
		pthread_mutex_init(&data->forks[i], NULL);
	i = 0;
	philos[0].left_f = &data->forks[0];
	philos[0].right_f = &data->forks[data->philos_qty - 1];
	while (++i < data->philos_qty)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

static int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	while (++i < data->philos_qty)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		mutex_update_u64(&philos[i].mut_last_eat_time,
			&philos[i].last_eat_time, get_time());
	}
	return (assign_forks(data));
}

static void	init_data_mutexes(t_data *data)
{
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_philos_qty, NULL);
	pthread_mutex_init(&data->mut_keep_loop, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->keep_loop = 1;
	data->nb_meals = -1;
	data->philos_qty = ft_atoi(argv[1]);
	data->die_time = (uint64_t)ft_atoi(argv[2]);
	data->eat_time = (uint64_t)ft_atoi(argv[3]);
	data->sleep_time = (uint64_t)ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	init_data_mutexes(data);
	data->philos = malloc(sizeof(t_philo) * data->philos_qty);
	if (data->philos == NULL)
		return (ERR_ALLOC_PHILOS);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_qty);
	if (data->forks == NULL)
		return (free(data->philos), ERR_ALLOC_FORKS);
	data->philo_ths = malloc(sizeof(pthread_t) * data->philos_qty);
	if (data->philo_ths == NULL)
		return (free(data->philos), free(data->forks), ERR_ALLOC_THREADS);
	return (init_philos(data));
}
