/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:23:04 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/08 15:27:26 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eat(t_philo *philo)
{
	printf("FOOD for %d\n", philo->id);
	return (0);
}

int time_to_sleep(t_philo *philo)
{
	printf("DREAMS for %d\n", philo->id);
	return (0);
}
