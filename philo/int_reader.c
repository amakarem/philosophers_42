/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:25:28 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 20:02:19 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_get_int(pthread_mutex_t *mutex, int *target)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = (int)(*target);
	pthread_mutex_unlock(mutex);
	return (value);
}

// int	get_keep_loop(t_data *data)
// {
// 	return (mutex_get_int(&data->mut_keep_loop, &data->keep_loop));
// }

// int	get_philos_qty(t_data *data)
// {
// 	return (mutex_get_int(&data->mut_philos_qty, &data->philos_qty));
// }

// int	get_philo_state(t_philo *philo)
// {
// 	return (mutex_get_int(&philo->mut_state, &philo->state));
// }

// int	get_nb_meals_philo_had(t_philo *philo)
// {
// 	return (mutex_get_int(&philo->mut_nb_meals_had, &philo->nb_meals_had));
// }

// uint64_t	get_die_time(t_data *data)
// {
// 	return (mutex_get_u64(&data->mut_die_t, &data->die_time));
// }

// uint64_t	get_sleep_time(t_data *data)
// {
// 	return (mutex_get_u64(&data->mut_sleep_t, &data->sleep_time));
// }

// uint64_t	get_last_eat_time(t_philo *philo)
// {
// 	return (mutex_get_u64(&philo->mut_last_eat_time, &philo->last_eat_time));
// }
