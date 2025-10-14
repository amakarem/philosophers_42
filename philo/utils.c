/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:53:03 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 15:59:02 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_return_max(int flag)
{
	if (flag == 1)
		return (2147483647);
	return (-2147483648);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		flag;

	flag = 1;
	nbr = 0;
	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		flag = (flag * -1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (nbr > 214748364 || (nbr == 214748364 && (str[i] - '0') > 7))
			return (ft_return_max(flag));
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * flag);
}
static void	destroy_mutexes(t_data *data)
{
	int	i;
	int	philos_qty;

	philos_qty = mutex_get_int(&data->mut_philos_qty, &data->philos_qty);
	i = -1;
	while (++i < philos_qty)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_philos_qty);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_loop);
	pthread_mutex_destroy(&data->mut_start_time);
}

void	free_data(t_data *data)
{
	destroy_mutexes(data);
	if (data->philo_ths)
		free(data->philo_ths);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	data->philo_ths = NULL;
	data->philos = NULL;
	data->forks = NULL;
}
