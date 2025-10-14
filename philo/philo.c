/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:33:17 by aelaaser          #+#    #+#             */
/*   Updated: 2025/10/14 16:03:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	int status;
	t_data	data;

	if (!validinput(argc, argv)) return (ERR_VALIDATION);
	status = init_data(&data, argc, argv);
	free_data(&data);
	return (status);
}