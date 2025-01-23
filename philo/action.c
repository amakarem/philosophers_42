/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:36:46 by aelaaser          #+#    #+#             */
/*   Updated: 2025/01/23 17:38:19 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, THINK);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, SLEEP);
	ft_usleep(get_sleep_time(philo->data));
	return (0);
}

void	set_keep_iterating(t_data *data, bool set_to)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = set_to;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}
