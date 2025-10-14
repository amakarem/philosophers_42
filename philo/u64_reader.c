/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u64_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:35:47 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 17:38:56 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_start_time(t_data *data)
{
	return (mutex_get_u64(&data->mut_start_time, &data->mut_start_time));
}

uint64_t	get_die_time(t_data *data)
{
	return (mutex_get_u64(&data->mut_die_t, &data->die_time));
}

uint64_t	get_sleep_time(t_data *data)
{
	return (mutex_get_u64(&data->mut_sleep_t, &data->sleep_time));
}

uint64_t	get_eat_time(t_data *data)
{
	return (mutex_get_u64(&data->mut_eat_t, &data->eat_time));
}

uint64_t	get_last_eat_time(t_philo *philo)
{
	return (mutex_get_u64(&philo->mut_last_eat_time, &philo->last_eat_time));
}
