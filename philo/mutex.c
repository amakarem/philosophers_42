/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:48:58 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 18:42:12 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_update_u64(pthread_mutex_t *mutex, uint64_t *target, uint64_t value)
{
	pthread_mutex_lock(mutex);
	*target = value;
	pthread_mutex_unlock(mutex);
}

uint64_t	mutex_get_u64(pthread_mutex_t *mutex, uint64_t *target)
{
	uint64_t	value;

	pthread_mutex_lock(mutex);
	value = *target;
	pthread_mutex_unlock(mutex);
	return (value);
}

void	mutex_update_int(pthread_mutex_t *mutex, int *target, int value)
{
	pthread_mutex_lock(mutex);
	*target = value;
	pthread_mutex_unlock(mutex);
}

void	mutex_increment(pthread_mutex_t *mutex, int *target)
{
	pthread_mutex_lock(mutex);
	(*target)++;
	pthread_mutex_unlock(mutex);
}

void	mutex_print(t_data *data, int id, char *msg)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_print);
	time = get_time() - mutex_get_u64(&data->mut_start_time, &data->start_time);
	if (mutex_get_int(&data->mut_keep_loop, &data->keep_loop))
		printf("%" PRIu64 " %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}
