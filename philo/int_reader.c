/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:25:28 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 19:37:54 by aelaaser         ###   ########.fr       */
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

int	get_keep_loop(t_data *data)
{
	return (mutex_get_int(&data->mut_keep_loop, &data->keep_loop));
}

int	get_philos_qty(t_data *data)
{
	return (mutex_get_int(&data->mut_philos_qty, &data->philos_qty));
}

int	get_philo_state(t_philo *philo)
{
	return (mutex_get_int(&philo->mut_state, &philo->state));
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	return (mutex_get_int(&philo->mut_nb_meals_had, &philo->nb_meals_had));
}
