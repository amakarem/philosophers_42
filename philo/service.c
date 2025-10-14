/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:09:13 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 17:55:01 by aelaaser         ###   ########.fr       */
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
