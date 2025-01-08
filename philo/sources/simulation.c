/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:01:28 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/07 14:08:52 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	to_simulation(t_data *data)
{
	t_philo	*philos;

	philos = init_philo(philos);
	if (!philos)
	{
		free(data);
		return (1);
	}
	return (0);
}
