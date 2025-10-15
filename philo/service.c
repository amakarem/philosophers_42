/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:09:13 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/15 20:56:20 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_died(t_philo *philo)
{
	uint64_t	time_since_last_meal;

	time_since_last_meal = get_time()
		- mutex_get_u64(&philo->mut_last_eat_time, &philo->last_eat_time);
	if (time_since_last_meal
		<= mutex_get_u64(&philo->data->mut_die_t, &philo->data->die_time))
		return (false);
	if (mutex_get_int(&philo->mut_state, &philo->state) == EATING)
		return (false);
	set_philo_state(philo, DEAD);
	return (true);
}

int	think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (mutex_get_int(&philo->mut_state, &philo->state) == DEAD)
		return (1);
	mutex_print(philo->data, philo->id, MSG_THINK);
	return (0);
}

int	to_sleep(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	if (mutex_get_int(&philo->mut_state, &philo->state) == DEAD)
		return (1);
	mutex_print(philo->data, philo->id, MSG_SLEEP);
	ft_usleep(mutex_get_u64(&philo->data->mut_sleep_t,
			&philo->data->sleep_time), philo->data);
	return (0);
}
