/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:37 by aelaaser          #+#    #+#             */
/*   Updated: 2025/02/01 21:54:59 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals_philo_had(philo) >= data->nb_meals)
		result = true;
	return (result);
}

bool	philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (get_time() - get_last_eat_time(philo) > get_die_time(data)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}

static void	notify_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		philos_qty;

	philos_qty = get_philos_qty(data);
	philos = data->philos;
	i = -1;
	while (++i < philos_qty)
		set_philo_state(&philos[i], DEAD);
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		philos_qty;

	data = (t_data *)data_p;
	i = -1;
	philos_qty = get_philos_qty(data);
	while (++i < philos_qty && get_keep_loop(data))
	{
		ft_usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_keep_loop(data) == true)
	{
		set_keep_loop(data, false);
		notify_all_philos(data);
	}
	return (NULL);
}

void	*all_alive_routine(void *data_p)
{
	int		i;
	int		philos_qty;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	philos_qty = get_philos_qty(data);
	i = -1;
	while (++i < philos_qty && get_keep_loop(data))
	{
		ft_usleep(1000);
		if (philo_died(&philos[i]) && get_keep_loop(data))
		{
			print_msg(data, philos[i].id, DIED);
			set_keep_loop(data, false);
			notify_all_philos(data);
			ft_usleep(1000 * philos_qty);
			break ;
		}
		if (i == philos_qty - 1)
			i = -1;
	}
	return (NULL);
}
