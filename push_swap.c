/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:07:52 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/21 22:58:29 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_cases_three(t_stack **a, int first, int second, int third)
{
	if (second > third && first > third)
	{
		swaping(a, NULL, 'a');
		rev_retating(a, NULL, 'a');
	}
	else if (second > third && first < third)
		swaping(a, NULL, 'a');
	else if (second < third && first > third)
		retating(a, NULL, 'a');
	else if (second < third && first < third)
		swaping(a, NULL, 'a');
}

void	sort_three_numbers(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second)
		check_cases_three(a, first, second, third);
	else
	{
		if ((second < third && first < third)
			|| (second > third && first < third))
		{
			swaping(a, NULL, 'a');
			retating(a, NULL, 'a');
		}
		else if (second > third && first > third)
			rev_retating(a, NULL, 'a');
	}
}

void	sort_for_numbers(t_stack **a, t_stack **b)
{
	int	i;

	i = find_node(*a, 0);
	ret_rev_b(b, a, i, 3);
	pushing(a, b, 'a');
	sort_three_numbers(a);
	pushing(a, b, 'b');
}

void	sort_five_numbers(t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	i = find_node(*a, 1);
	ret_rev_b(b, a, i, 5);
	pushing(b, a, 'a');
	// j = find_node(*a, 0);
	// ret_rev_b(b, a, j, 4);
	// pushing(a, b, 'a');
	sort_three_numbers(a);
	pushing(a, b, 'b');
	// pushing(a, b, 'b');
}

void	sort_smaler_numbers(t_stack **a, t_stack **b, int i, int j)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		swaping(a, b, 'a');
	else if (size == 3)
		sort_three_numbers(a);
	else if (size == 4)
		sort_for_numbers(a, b);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*h;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (argc > 1)
	{
		if (check_num(argc, argv) == 0)
			return (1);
		else
		{
			add_node(&a, argv, argc);
			min_index(&a);
			if (sorted(a) == 1)
				return (1);
			sort_smaler_numbers(&a, &b, i, j);
			h = a;
			while (h)
			{
				printf("%d\t---->\t%d\n", h->data, h->index);
				h = h->next;
			}
		}
	}
	return (0);
}
