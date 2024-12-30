/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:39:40 by aelaaser          #+#    #+#             */
/*   Updated: 2024/12/30 15:58:41 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((uint64_t)(time.tv_sec) * 1000 + (time.tv_usec / 1000));
}

void	leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	uint64_t	start_time;
	uint64_t	now;

	atexit(&leaks);
	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount of arguments"));
	printf("\n starting... %s", argv[0]);
	start_time = get_time();
	usleep(10000);
	now = get_time();
	printf("\n Time: %llu", now - start_time);
	fflush(stdout);
	return (0);
}
