/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:08:14 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 15:11:28 by aelaaser         ###   ########.fr       */
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
