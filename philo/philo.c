/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:33:17 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 18:00:27 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	mutex_update_u64(&philo->mut_last_eat_time, &philo->last_eat_time, get_time());
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (mutex_get_int(&philo->mut_state, &philo->state) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (mutex_get_int(&philo->mut_state, &philo->state) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (mutex_get_int(&philo->mut_state, &philo->state) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
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