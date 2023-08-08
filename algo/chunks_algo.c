/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:01:06 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 20:39:32 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	here we have function for:
		# r_indexes	(check if the number is less than chunk/2
			if it is should retate it down)
			
		# ret_rev_b	(check the position of index we search for and
			retate/reverse retate it to send it at the top of stack)

		# check_smaller (check if the top stack is greater than next and swap it)
		
		# push_2b (pushing to stack b chunk by chunk)
		
		# push_2a (pushing to stack b biggest index in everytime)
*/
int	r_indexes(t_stack **a, t_stack **b, int num, int real)
{
	t_stack	*last;

	last = *b;
	if ((ft_lstsize(*b) >= 2) && (last->index >= num - real)
		&& (last->index < num - (real / 2)) && *a && (*a)->index > num)
		return (2);
	else if ((ft_lstsize(*b) >= 2) && (last->index >= num - real)
		&& (last->index < num - (real / 2)))
		return (1);
	else
		return (0);
}

void	ret_rev_b(t_stack **a, t_stack **b, int i, int num)
{
	if (i <= num / 2)
	{
		while (i > 0)
		{
			retating(a, b, 'b');
			i--;
		}
	}
	else
	{
		while (i <= num)
		{
			rev_retating(a, b, 'b');
			i++;
		}
	}
}

void	check_smaller(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 1)
	{
		if ((*a)->index > (*a)->next->index)
			swaping(a, b, 'a');
		else
			return ;
	}
	else
		return ;
}

void	push_2a(t_stack **a, t_stack **b, int i, int j)
{
	int	num;

	while (*b)
	{
		if (i == -1 && j == -1)
			num = ft_lstsize(*b) - 1;
		i = find_node(*b, num);
		j = find_node(*b, num - 1);
		if (i != -1 && !check_closer(i, j, ft_lstsize(*b) - 1))
		{
			ret_rev_b(a, b, i, ft_lstsize(*b) - 1);
			pushing(a, b, 'b');
			if (j == -1)
				check_smaller(a, b);
		}
		else if (j != -1 && check_closer(i, j, ft_lstsize(*b) - 1))
		{
			ret_rev_b(a, b, j, ft_lstsize(*b) - 1);
			pushing(a, b, 'b');
			if (i == -1)
				check_smaller(a, b);
		}
	}
}

void	push_2b(t_stack **a, t_stack **b)
{
	int		num;
	size_t	real;

	num = division_num(a);
	real = num;
	while (*a)
	{
		if ((*a)->index <= num)
		{
			pushing(a, b, 'a');
			if (r_indexes(a, b, num, real) == 1)
				retating(a, b, 'b');
			else if (r_indexes(a, b, num, real) == 2)
				retating(a, b, 't');
		}
		else
		{
			retating(a, b, 'a');
		}
		if (ft_lstsize(*b) == num)
			num += real;
	}
}
