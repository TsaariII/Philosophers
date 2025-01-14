/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:23:04 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/14 11:32:42 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_forks(t_philo *philo)
{
	if (the_end(philo))
		return (1);
	pthread_mutex_lock(philo->l_fork);
	document_moment(philo, "has a taken fork", 0);
	pthread_mutex_lock(philo->r_fork);
	document_moment(philo, "has a taken fork", 0);
	if (the_end(philo))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	return (0);
}

static void	is_this_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->lock);
	if (philo->meals == philo->data->meals)
		philo->data->full += 1;
	pthread_mutex_unlock(&philo->data->lock);
}

int	eat(t_philo *philo)
{
	if (the_end(philo))
		return (1);
	if (take_forks(philo))
		return (1);
	document_moment(philo, "is eating", 0);
	pthread_mutex_lock(&philo->data->lock);
	philo->last_meal = what_time() - philo->data->start;
	pthread_mutex_unlock(&philo->data->lock);
	if (standby_of_reason(philo, philo->data->time_eat))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	philo->meals += 1;
	is_this_enough(philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	went_to_bed(t_philo *philo)
{
	if (the_end(philo))
		return (1);
	document_moment(philo, "is sleeping", 0);
	if (standby_of_reason(philo, philo->data->time_sleep))
		return (1);
	return (0);
}
