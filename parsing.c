/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:35:09 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/24 17:22:49 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	here we have function for:
		# check_all (check is the charecters are a digits)
		
		# convert_and_check (covert characters to long long numbers
			and check the min/max of integer range)
			
		# check_doubles (check if there is a duplicate number)
		
		# check_num (in this function we check all the staff above)
*/
static int	check_all(char **splited, size_t i)
{
	size_t	j;

	j = 0;
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
	size_t	j;
	long	*nums;

	j = 0;
	nums = malloc(sizeof(long) * i);
	if (!nums)
		return (0);
	i = 1;
	while (str[i])
		nums[j++] = ft_atoi(str[i++]);
	j = 0;
	while (j < i - 1)
	{
		if (nums[j] < -2147483648 || nums[j] > 2147483647)
			return (free(nums), 0);
		j++;
	}
	return (free(nums), 1);
}

static int	check_doubles(char **str, size_t i)
{
	size_t	j;
	size_t	k;
	long	*nums;

	j = 0;
	nums = malloc(sizeof(long) * i);
	if (!nums)
		return (0);
	i = 1;
	while (str[i])
		nums[j++] = ft_atoi(str[i++]);
	j = 0;
	while (j < i - 1)
	{
		k = j + 1;
		while (k < i - 1)
		{
			if (nums[j] == nums[k])
				return (free(nums), 0);
			k++;
		}
		j++;
	}
	return (free(nums), 1);
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
	free(joined);
	while (splited[i])
	{
		if (!check_all(splited, i))
			return (ft_free(splited), write(1, "Error\n", 6), 0);
		i++;
	}
	if (check_doubles(splited, i) == 0)
		return (ft_free(splited), write(1, "Error\n", 6), 0);
	if (convert_and_check(splited, i) == 0)
		return (ft_free(splited), write(1, "Error\n", 6), 0);
	ft_free(splited);
	return (1);
}
