/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:53:03 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 15:18:23 by aelaaser         ###   ########.fr       */
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

void	mutex_update_u64(pthread_mutex_t *mutex, uint64_t *target, uint64_t value)
{
	pthread_mutex_lock(mutex);
	*target = value;
	pthread_mutex_unlock(mutex);
}
