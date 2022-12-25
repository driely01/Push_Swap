/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:53:39 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/25 12:37:05 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static long	ft_calculater(const char *str, int i, int sign)
{
	long	res;
	long	old;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		old = res;
		res *= 10;
		if ((res / 10) != old && sign == 1)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		if ((res / 10) != old && sign == -1)
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		res += (str[i] - 48);
		i++;
	}
	return (res * sign);
}

long	ft_atoi(const char *str)
{
	long	i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (ft_calculater(str, i, sign));
}
