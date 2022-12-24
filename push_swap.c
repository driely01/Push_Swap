/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:07:52 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/24 21:07:23 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (1);
			sort_smaller_numbers(&a, &b, i, j);
		}
		ft_lstclear(&a);
	}
	return (0);
}
