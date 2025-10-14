/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:33:17 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 16:37:46 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_threads(t_data *data)
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


int main(int argc, char **argv)
{
	int status;
	t_data	data;

	if (!validinput(argc, argv)) return (ERR_VALIDATION);
	status = init_data(&data, argc, argv);
	free_data(&data);
	return (status);
}