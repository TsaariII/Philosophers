/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:22:23 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/08 15:52:32 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	starving_philo(t_data *data)
{
	size_t	time;
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->lock);
		if (data->running  == 0)
		{
			time = what_time() - data->start;
			if (time - data->philos[i].last_meal > data->time_eat)
			{
				pthread_mutex_unlock(&data->lock);
				document_moment(&data->philos[i], "died", 1);
				return (1);
			}
		}
		pthread_mutex_unlock(&data->lock);
		i++;
	}
	return (0);
}

int	end_of_cycle(t_data *data)
{
	// int	philos;
	// int	meals;

	if (starving_philo(data))
		return (1);
	return (0);
}

void	cycle_of_extistence(t_data *data)
{
	while (1)
	{
		if (end_of_cycle(data))
			break ;
	}
	unite_in_peace(data);
	cleaner(data);
}
