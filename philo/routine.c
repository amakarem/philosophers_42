/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:05:20 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/15 16:16:57 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	mutex_update_u64(&philo->mut_last_eat_time,
		&philo->last_eat_time, get_time());
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (mutex_get_int(&philo->mut_state, &philo->state) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (mutex_get_int(&philo->mut_state, &philo->state) == DEAD
			|| to_sleep(philo) != 0)
			break ;
		if (mutex_get_int(&philo->mut_state, &philo->state) == DEAD
			|| think(philo) != 0)
			break ;
	}
	return (NULL);
}

static void	kill_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		philos_qty;

	philos_qty = mutex_get_int(&data->mut_philos_qty, &data->philos_qty);
	philos = data->philos;
	i = -1;
	while (++i < philos_qty)
		set_philo_state(&philos[i], DEAD);
}

static void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		philos_qty;

	data = (t_data *)data_p;
	i = -1;
	philos_qty = mutex_get_int(&data->mut_philos_qty, &data->philos_qty);
	while (++i < philos_qty
		&& mutex_get_int(&data->mut_keep_loop, &data->keep_loop))
	{
		usleep(1);
		if (mutex_get_int(&data->philos[i].mut_nb_meals_had,
				&data->philos[i].nb_meals_had)
			< data->nb_meals)
			i = -1;
	}
	if (mutex_get_int(&data->mut_keep_loop, &data->keep_loop) == true)
	{
		kill_all_philos(data);
		mutex_update_int(&data->mut_keep_loop, &data->keep_loop, 0);
	}
	return (NULL);
}

static void	*all_alive_routine(void *data_p)
{
	int		i;
	int		philos_qty;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	philos_qty = mutex_get_int(&data->mut_philos_qty, &data->philos_qty);
	i = -1;
	while (++i < philos_qty
		&& mutex_get_int(&data->mut_keep_loop, &data->keep_loop))
	{
		if (is_died(&philos[i])
			&& mutex_get_int(&data->mut_keep_loop, &data->keep_loop))
		{
			kill_all_philos(data);
			mutex_print(data, philos[i].id, MSG_DIED);
			mutex_update_int(&data->mut_keep_loop, &data->keep_loop, 0);
			break ;
		}
		if (i == philos_qty - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = mutex_get_int(&data->mut_philos_qty, &data->philos_qty);
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&all_alive_routine, data))
		return (1);
	if (data->nb_meals > 0
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full_routine, data))
		return (1);
	return (0);
}
