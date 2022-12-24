/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:09:32 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/24 21:13:13 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_closer(int ind1, int ind2, int length)
{
	if (ind1 > length / 2)
		ind1 = length - ind1;
	if (ind2 > length / 2)
		ind2 = length - ind2;
	if (ind1 == -1)
		return (1);
	else if (ind2 == -1)
		return (0);
	if (ind1 > ind2)
		return (1);
	else
		return (0);
}

int	find_node(t_stack *b, int in)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index == in)
			return (i);
		i++;
		b = b->next;
	}
	return (-1);
}

int	division_num(t_stack **stack)
{
	int	num;

	num = 0;
	if (ft_lstsize(*stack) > 5 && ft_lstsize(*stack) <= 100)
		num = ft_lstsize(*stack) / 5;
	else if (ft_lstsize(*stack) > 100 && ft_lstsize(*stack) <= 500)
		num = ft_lstsize(*stack) / 9;
	else
		num = ft_lstsize(*stack) / 10;
	return (num);
}

void	give_indexs(t_stack **a, int i, int min)
{
	t_stack	*top;

	top = *a;
	while (top)
	{
		if (top->data == min)
		{
			top->index = i;
			break ;
		}
		top = top->next;
	}
}

void	min_index(t_stack **a)
{
	t_stack	*top;
	int		min;
	int		i;

	i = -1;
	while (++i < ft_lstsize(*a))
	{
		top = *a;
		min = INT_MAX;
		while (top)
		{
			if (top->index == -1)
				if (top->data < min)
					min = top->data;
			top = top->next;
		}
		give_indexs(a, i, min);
	}
}
