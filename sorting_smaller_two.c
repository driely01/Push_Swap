/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_smaller_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:20:45 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/27 15:33:46 by del-yaag         ###   ########.fr       */
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
static void	fill_node(t_stack **a, t_stack **top, char **splited)
{
	size_t	i;

	i = 0;
	while (splited[++i])
	{
		if (!(*a))
		{
			*a = malloc(sizeof(t_stack));
			*top = *a;
		}
		else
		{
			(*a)->next = malloc(sizeof(t_stack));
			*a = (*a)->next;
		}
		if (!(*a))
		{
			ft_lstclear(a);
			return ;
		}
		(*a)->data = (int)ft_atoi(splited[i]);
		(*a)->index = -1;
	}
}

void	add_node(t_stack **a, char **argv, int argc)
{
	char	*joined;
	char	**splited;
	t_stack	*top;

	joined = ft_strjoin(argc, argv, " ");
	splited = ft_split(joined, ' ');
	free(joined);
	fill_node(a, &top, splited);
	ft_free(splited);
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
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}
