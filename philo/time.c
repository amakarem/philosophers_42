/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:08:14 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 16:41:35 by aelaaser         ###   ########.fr       */
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

void	ft_usleep(uint64_t sleep_time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

void	ft_wait(u_int64_t wakeup_time)
{
	int			margin;
	uint64_t	time;

	margin = 5;
	while (1)
	{
		time = get_time();
		if (wakeup_time <= time + margin)
		{
			while (wakeup_time > time)
				time = get_time();
			break ;
		}
		else
			usleep(1000 * (wakeup_time - time - margin));
	}
}
