/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:35:09 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/17 11:53:32 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_all(char **splited, size_t i)
{
	size_t	j;

	j = 0;
	if (ft_strlen(splited[i]) > 11)
		return (0);
	while (splited[i][j])
	{
		if (splited[i][j] >= '0' && splited[i][j] <= '9')
			j++;
		else
		{
			if (splited[i][j] == '-' && j == 0)
			{
				j++;
				if (splited[i][j] >= '0' && splited[i][j] <= '9')
					j++;
				else
					return (0);
			}
			else
				return (0);
		}
	}
	return (1);
}

static int	convert_and_check(char **str, size_t i)
{
	size_t		j;
	long long	*nums;

	j = 0;
	nums = malloc(sizeof(long long) * i);
	i = 1;
	while (str[i])
		nums[j++] = ft_atoi(str[i++]);
	j = 0;
	while (j < i - 1)
	{
		if (nums[j] < -2147483648 || nums[j] > 2147483647)
			return (0);
		j++;
	}
	return (1);
}

static int	check_doubles(char **str, size_t i)
{
	size_t		j;
	size_t		k;
	long long	*nums;

	j = 0;
	nums = malloc(sizeof(long long) * i);
	i = 1;
	while (str[i])
		nums[j++] = ft_atoi(str[i++]);
	j = 0;
	while (j < i - 1)
	{
		k = j + 1;
		while (k < i - 1 )
		{
			if (nums[j] == nums[k])
				return (0);
			k++;
		}
		j++;
	}
	return (1);
}

int	check_num(int argc, char **argv)
{
	char	*joined;
	char	**splited;
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	joined = ft_strjoin(argc, argv, " ");
	splited = ft_split(joined, ' ');
	while (splited[i])
	{
		if (!check_all(splited, i))
			return (write(1, "Error\n", 6), 0);
		i++;
	}
	if (check_doubles(splited, i) == 0)
		return (write(1, "Error\n", 6), 0);
	if (convert_and_check(splited, i) == 0)
		return (write(1, "Error\n", 6), 0);
	return (1);
}
