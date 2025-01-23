/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:31:17 by aelaaser          #+#    #+#             */
/*   Updated: 2025/01/23 17:55:22 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_instruction(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die ");
	printf("time_to_eat time_to_sleep ");
	printf("number_of_times_each_philosopher_must_eat ");
	printf("(optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die: 60+\n");
	printf("time_to_eat: 60+\n");
	printf("time_to_sleep: 60+\n");
	printf("number_of_times_each_philosopher_must_eat: ");
	printf("0+\n");
}

static int	wrong_input_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (WRONG_INPUT);
	if (ft_atoi(argv[i]) < 1 || ft_atoi(argv[i]) > 200)
		return (WRONG_INPUT);
	while (++i < 5)
	{
		if (ft_atoi(argv[i]) < 60)
			return (WRONG_INPUT);
	}
	return (0);
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
				return (WRONG_INPUT);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (WRONG_INPUT);
	if (argc > 6)
		return (WRONG_INPUT);
	if (is_input_digit(argc, argv) != 0)
		return (WRONG_INPUT);
	if (wrong_input_check(argc, argv))
		return (WRONG_INPUT);
	return (0);
}
