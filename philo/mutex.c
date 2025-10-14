/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:48:58 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 15:52:33 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_update_u64(pthread_mutex_t *mutex, uint64_t *target, uint64_t value)
{
	pthread_mutex_lock(mutex);
	*target = value;
	pthread_mutex_unlock(mutex);
}
int	mutex_get_int(pthread_mutex_t *mutex, int *target)
{

	int	value;

	pthread_mutex_lock(mutex);
	value = (int)(*target);
	pthread_mutex_unlock(mutex);
	return (value);
}
