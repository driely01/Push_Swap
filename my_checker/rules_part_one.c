/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:00 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/23 17:20:42 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstsize(t_stack *lst)
{
	size_t	count;
	t_stack	*ptr;

	count = 0;
	if (!lst)
		return (count);
	ptr = lst;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

void	swap_all(t_stack **a)
{
	t_stack	*top;
	t_stack	*temp;

	if (ft_lstsize(*a) <= 1)
		return ;
	top = *a;
	temp = top->next;
	top->next = temp->next;
	temp->next = top;
	*a = temp;
}

void	swaping(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		swap_all(a);
	else if (c == 'b')
		swap_all(b);
	else if (c == 't')
	{
		swap_all(a);
		swap_all(b);
	}
}

void	push_all(t_stack **a, t_stack **b)
{
	t_stack	*head;

	if (ft_lstsize(*a) == 0)
		return ;
	head = (*a)->next;
	(*a)->next = (*b);
	(*b) = (*a);
	(*a) = head;
}

void	pushing(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		push_all(a, b);
	else if (c == 'b')
		push_all(b, a);
}
