/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:25:28 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/15 14:31:14 by aelaaser         ###   ########.fr       */
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
