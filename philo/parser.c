/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:36:59 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 13:48:36 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	show_instruction(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("Usage:\n./philo philos_qty time_to_die time_to_eat time_to_sleep ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat (optional argument)\n\n");
	printf("Example:\n./philo 4 800 200 200 5\n\n");
	printf("Parameter Ranges:\n");
	printf("philos_qty: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: 0+\n");
}


int	validinput(int argc, char **argv)
{
	if (argc < 5)
		return (show_instruction(), 0);
	if (argc > 6)
		return (show_instruction(), 0);
	return (1);
}
