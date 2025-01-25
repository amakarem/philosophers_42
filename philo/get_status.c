/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:46:39 by aelaaser          #+#    #+#             */
/*   Updated: 2025/01/25 18:44:43 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_keep_loop(t_data *data)
{
	bool	keep_loop;

	pthread_mutex_lock(&data->mut_keep_loop);
	keep_loop = data->keep_loop;
	pthread_mutex_unlock(&data->mut_keep_loop);
	return (keep_loop);
}

int	get_philos_qty(t_data *data)
{
	int	philos_qty;

	pthread_mutex_lock(&data->mut_philos_qty);
	philos_qty = data->philos_qty;
	pthread_mutex_unlock(&data->mut_philos_qty);
	return (philos_qty);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}
