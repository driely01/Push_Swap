/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_smaller_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:20:45 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/22 15:36:20 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	here we have function for:
		# add_node (to fill stack 'a')
		
		# sort_five_numbers (for sorting a five numbers)
		
		# sort_smaller_numbers (in this function we sort both
			"smaller and biggest nnumbers")
			
		# sorted (check if the list is sorted or not)
*/
void	add_node(t_stack **a, char **argv, int argc)
{
	char	*joined;
	char	**splited;
	size_t	i;
	t_stack	*top;

	i = 0;
	joined = ft_strjoin(argc, argv, " ");
	splited = ft_split(joined, ' ');
	while (splited[++i])
	{
		if (!(*a))
		{
			*a = malloc(sizeof(t_stack));
			top = *a;
		}
		else
		{
			(*a)->next = malloc(sizeof(t_stack));
			*a = (*a)->next;
		}
		(*a)->data = (int)ft_atoi(splited[i]);
		(*a)->index = -1;
	}
	(*a)->next = NULL;
	*a = top;
}

void	sort_five_numbers(t_stack **a, t_stack **b)
{
	int	i;

	i = find_node(*a, 0);
	ret_rev_a_for_five(a, i);
	pushing(a, b, 'a');
	sort_four_numbers(a, b, 1);
	pushing(a, b, 'b');
}

void	sort_smaller_numbers(t_stack **a, t_stack **b, int i, int j)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		swaping(a, b, 'a');
	else if (size == 3)
		sort_three_numbers(a);
	else if (size == 4)
		sort_four_numbers(a, b, 0);
	else if (size == 5)
		sort_five_numbers(a, b);
	else if (size >= 6)
	{
		push_2b(a, b);
		push_2a(a, b, i, j);
	}
}

int	sorted(t_stack *a)
{
	int	num;

	while (a)
	{
		if (a->next)
			num = a->next->data;
		else
			num = a->data;
		if (num < a->data)
			return (0);
		a = a->next;
	}
	return (1);
}
