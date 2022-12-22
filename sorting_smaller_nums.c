/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_smaller_nums.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:09:02 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/22 14:19:59 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	here we have function for:
		# check_cases_three (check some a helf cases of three numbers)
		
		# sort_three_numbers (for sorting the 3 numbers >just a hardcode<)
		
		# ret_rev_a (check the position of index we search for and
			retate/reverse retate it to send it at the top of stack)
			
		# sort_four_numbers (sorting four numbers)
		
		# ret_rev_a_for_five (check the position of index we search for and
			retate/reverse retate it to send it at the top of stack 
			>>this just for five numbers<<)
*/
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
		if (first < third && second < third)
			return ;
		else if ((second < third && first < third)
			|| (second > third && first < third))
		{
			swaping(a, NULL, 'a');
			retating(a, NULL, 'a');
		}
		else if (second > third && first > third)
			rev_retating(a, NULL, 'a');
	}
}

void	ret_rev_a(t_stack **a, int i, int num)
{
	if (i <= num / 2)
	{
		while (i > 0)
		{
			retating(a, NULL, 'a');
			i--;
		}
	}
	else
	{
		while (i <= num)
		{
			rev_retating(a, NULL, 'a');
			i++;
		}
	}
}

void	sort_four_numbers(t_stack **a, t_stack **b, int index)
{
	int	i;

	i = find_node(*a, index);
	ret_rev_a(a, i, 3);
	pushing(a, b, 'a');
	sort_three_numbers(a);
	pushing(a, b, 'b');
}

void	ret_rev_a_for_five(t_stack **a, int i)
{
	if (i <= 3)
	{
		while (i > 0)
		{
			retating(a, NULL, 'a');
			i--;
		}
	}
	else
	{
		while (i <= 4)
		{
			rev_retating(a, NULL, 'a');
			i++;
		}
	}
}
