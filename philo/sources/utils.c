/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:28:52 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/07 14:30:10 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
