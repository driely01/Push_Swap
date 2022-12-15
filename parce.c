/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:35:09 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/15 15:36:37 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compaire_numbers(const char *s1, const char *s2)
{
	size_t			i;
	int				checker;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	checker = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] > str2[i] || str1[i] < str2[i])
			checker += str1[i] - str2[i];
		i++;
	}
	if (checker != 0)
		return (1);
	else
		return (0);
}

static int	check_double(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (compaire_numbers(argv[i], argv[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

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
	if (check_double(splited) == 0)
		return (write(1, "Error\n", 6), 0);
	if (convert_and_check(splited, i) == 0)
		return (write(1, "Error\n", 6), 0);
	return (1);
}
