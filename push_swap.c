/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:07:52 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/25 12:23:22 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_spaces(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i] == 0)
			return (write(1, "Error\n", 6), 0);
		if (!find_spaces(str[i]))
			return (write(1, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (argc > 1)
	{
		if (check_num(argc, argv) == 0)
			exit (0);
		else
		{
			add_node(&a, argv, argc);
			min_index(&a);
			if (sorted(a) == 1)
				return (0);
			sort_smaller_numbers(&a, &b, i, j);
		}
		ft_lstclear(&a);
	}
	return (0);
}
