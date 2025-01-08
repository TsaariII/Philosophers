/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:01:28 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/08 11:48:32 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*day(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->lock);
	if (philo->data->num_philo == 1);
	{
		just_one(philo);
		return (philo);
	}
	no_fork(philo);
	while (!the_end(philo))
	{
		if (eat(philo))
			break ;
		if (time_to_sleep(philo))
			break ;
		if (!the_end(philo))
			printf("is thinking");
		else
			break ;
	}
	return (philo);
}

void	to_simulation(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->lock);
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &day, (void *)&data->philos[i]))
		{
			printf("FAIL\n");
		}
		i++;
	}
	return (0);
}
