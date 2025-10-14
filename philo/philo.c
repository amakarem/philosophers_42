/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:33:17 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 18:43:52 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_data *data)
{
	int	i;
	int	philos_qty;

	philos_qty = get_philos_qty(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (data->nb_meals > 0
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < philos_qty)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int status;
	t_data	data;

	if (!validinput(argc, argv)) return (ERR_VALIDATION);
	status = init_data(&data, argc, argv);
	if (status == 0)
	{
		create_threads(&data);
		join_threads(&data);
	}
	free_data(&data);
	return (status);
}
