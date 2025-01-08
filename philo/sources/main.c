/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:51:26 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/08 15:28:49 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	printer(t_data *data)
{
	printf("*DATA*\n");
	printf("\tNo. philos: %d\n", data->num_philo);
	printf("\tTime to die: %zu\n", data->time_death);
	printf("\tTime to eat: %zu\n", data->time_eat);
	printf("\tTime to sleep: %zu\n", data->time_sleep);
	printf("\tMeals: %d\n", data->meals);
	printf("\tRunning: %d\n", data->running);
	printf("\tStart: %zu\n\n", data->start);
	int i = 0;
	while (i < data->num_philo)
	{
		printf("*PHILO %d*\n", data->philos[i].id);
		printf("\tMeals: %d\n", data->philos[i].meals);
		printf("\tLast meal: %zu\n", data->philos[i].last_meal);
		printf("\tTime to die: %zu\n", data->philos[i].data->time_death);
		printf("\tTime to eat: %zu\n", data->philos[i].data->time_eat);
		printf("\tTime to sleep: %zu\n", data->philos[i].data->time_sleep);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		informer();
		return (1);
	}
	data = init_data(argc, argv);
	printer(data);
	if (!data)
		return (1);
	create_simulation(data);
	cycle_of_extince(data);
	return (0);
}

