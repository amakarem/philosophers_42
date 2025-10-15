/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:08:14 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/15 20:59:46 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	now;
	uint64_t		milliseconds;

	if (gettimeofday(&now, NULL) != 0)
		return (0);
	milliseconds = (uint64_t)now.tv_sec * 1000;
	milliseconds += now.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep(uint64_t sleep_time, t_data *data)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
	{
		if (!mutex_get_int(&data->mut_keep_loop, &data->keep_loop))
			break ;
		usleep(500);
	}
}
