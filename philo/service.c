/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:09:13 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 18:40:20 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool is_died(t_philo *philo)
{
    uint64_t	time_since_last_meal;
	
	time_since_last_meal = get_time() - get_last_eat_time(philo);
    if (time_since_last_meal <= get_die_time(philo->data))
        return false;
    if (get_philo_state(philo) == EATING)
        return false;
    set_philo_state(philo, DEAD);
    return true;
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
	if (get_philo_state(philo) == DEAD)
		return (1);
	mutex_print(philo->data, philo->id, MSG_SLEEP);
	ft_usleep(get_sleep_time(philo->data));
	return (0);
}
