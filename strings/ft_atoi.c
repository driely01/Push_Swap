/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:53:39 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 20:38:07 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_calculater(char *str, int i, int sign)
{
	long	res;
	long	old;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		old = res;
		res *= 10;
		if ((res / 10) != old && sign == 1)
			return (21474836470);
		if ((res / 10) != old && sign == -1)
			return (21474836470);
		res += (str[i] - 48);
		i++;
	}
	return (res * sign);
}

long	ft_atoi(char *str)
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
