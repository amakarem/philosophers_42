/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:50:22 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 19:42:09 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_state(t_philo *philo, int state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

static int	take_fork(t_philo *philo, t_fork_side side)
{
	if (is_died(philo) || get_philo_state(philo) == DEAD)
		return (1);
	if (side == LEFT)
		pthread_mutex_lock(philo->left_f);
	else
	{
		pthread_mutex_lock(philo->right_f);
	}
	mutex_print(philo->data, philo->id, MSG_TAKE_FORKS);
	return (0);
}

static int	handle_1_philo(t_philo *philo)
{
	take_fork(philo, LEFT);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, DEAD);
	pthread_mutex_unlock(philo->left_f);
	return (1);
}

static int	take_forks(t_philo *philo)
{
	if (mutex_get_int(&philo->data->mut_philos_qty,
			&philo->data->philos_qty) == 1)
		return (handle_1_philo(philo));
	if (philo->left_f < philo->right_f)
	{
		if (take_fork(philo, LEFT) != 0)
			return (1);
		if (take_fork(philo, RIGHT) != 0)
		{
			pthread_mutex_unlock(philo->left_f);
			return (1);
		}
	}
	else
	{
		if (take_fork(philo, RIGHT) != 0)
			return (1);
		if (take_fork(philo, LEFT) != 0)
		{
			pthread_mutex_unlock(philo->right_f);
			return (1);
		}
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	mutex_print(philo->data, philo->id, MSG_EAT);
	mutex_update_u64(&philo->mut_last_eat_time,
		&philo->last_eat_time, get_time());
	ft_usleep(mutex_get_u64(&philo->data->mut_eat_t, &philo->data->eat_time));
	mutex_increment(&philo->mut_nb_meals_had, &philo->nb_meals_had);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	return (0);
}
