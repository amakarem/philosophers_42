/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:36:59 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 13:56:40 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	show_instruction(void)
{
	printf("\n******WRONG INPUT!*****\n\n");
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

static int	is_input_digit(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] < '0' || argv[i][k] > '9')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	validinput(int argc, char **argv)
{
	argv = NULL;
	if (argc < 5 || argc > 6)
		return (show_instruction(), 0);
	if (!is_input_digit(argc, argv))
		return (show_instruction(), 0);
	return (1);
}
