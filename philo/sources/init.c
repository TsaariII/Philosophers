/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:26:07 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/06 11:53:58 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	missing_value(t_data *data, int num)
{
	if (data->num_philo == 0 || data->time_death == 0 || data->time_eat == 0
		|| data->time_sleep == 0)
		return (1);
	if (num == 6 && data->meals == 0)
		return (1);
	return (0);
}

int	only_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	is_this_sign(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		return (0);
	while (str[i])
	{
		if (only_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	str_to_int(char *str)
{
	long long int	res;
	int				i;

	i = 0;
	res = 0;
	if (!is_this_sign(str))
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		if (res > INT_MAX)
			return (0);
		i++;
	}
	return ((int)res);
}

t_data	*init_data(int num, char **args)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
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
	return (data);
}
