/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:31:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/08 15:21:31 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

void	informer(void)
{
	write(2, "\nInvalid arguments\n\n", 21);
	printf("Usage:\n\tnumber_of_philosophers needs to at least 1\n");
	printf("\ttime_to_die needs to at least 1\n");
	printf("\ttime_to_eat needs to at least 1\n");
	printf("\time_to_sleep needs to at least 1\n");
	printf("\tnumber_of_times_each_philosopher_must_eat needs to at least 1\n");
}

int	the_end(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->data->running == 0)
	{
		pthread_mutex_unlock(&philo->data->lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->lock);
	return (0);
}
