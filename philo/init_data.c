/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:56:47 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 15:02:19 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	data->keep_loop = true;
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
		return (2);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philos_qty);
	if (data->forks == NULL)
		return (free(data->philos), 2);
	data->philo_ths = malloc(sizeof(pthread_t) * data->philos_qty);
	if (data->philo_ths == NULL)
		return (free(data->philos), free(data->forks), 2);
	return (0);
}
