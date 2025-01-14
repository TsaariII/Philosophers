/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:26:07 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/14 18:08:10 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	the_philo(t_data *data, t_philo *philo, int chair)
{
	philo->data = data;
	philo->l_fork = &data->forks[chair];
	philo->r_fork = &data->forks[(chair + 1) % data->num_philo];
	philo->id = chair + 1;
	philo->last_meal = 0;
	philo->meals = 0;
}

static int	create_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
	{
		while (i > data->num_philo)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
		free(data);
		return (1);
	}
	i = 0;
	while (i < data->num_philo)
	{
		the_philo(data, &data->philos[i], i);
		i++;
	}
	return (0);
}

static int	set_the_table(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->lock, NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
	{
		pthread_mutex_destroy(&data->lock);
		return (1);
	}
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			while (i > 0)
				pthread_mutex_destroy(&data->forks[i--]);
			pthread_mutex_destroy(&data->lock);
			free(data->forks);
		}
		i++;
	}
	return (0);
}

static int	missing_value(t_data *data, int num)
{
	if (data->num_philo == 0 || data->time_death == 0 || data->time_eat == 0
		|| data->time_sleep == 0)
		return (1);
	if (num == 6 && data->meals == 0)
		return (1);
	return (0);
}

t_data	*init_data(int num, char **args)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_philo = str_to_int(args[1]);
	data->time_death = str_to_int(args[2]);
	data->time_eat = str_to_int(args[3]);
	data->time_sleep = str_to_int(args[4]);
	if (num == 6)
		data->meals = str_to_int(args[5]);
	else
		data->meals = -1;
	if (missing_value(data, num))
	{
		free(data);
		informer();
		return (NULL);
	}
	if (set_the_table(data))
		return (NULL);
	if (create_philos(data))
		return (NULL);
	return (data);
}
