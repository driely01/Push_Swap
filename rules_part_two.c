/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:21 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/15 15:40:51 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ptr;

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	ptr = lst;
	return (ptr);
}

void	retate_all(t_stack **a)
{
	t_stack	*last;
	t_stack	*head;

	head = (*a)->next;
	last = ft_lstlast(*a);
	last->next = *a;
	last->next->next = NULL;
	*a = head;
}

void	retating(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		retate_all(a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		retate_all(b);
		write(1, "rb\n", 3);
	}
	else if (c == 't')
	{
		retate_all(a);
		retate_all(b);
		write(1, "rr\n", 3);
	}
}

void	rev_retate(t_stack **a)
{
	t_stack	*blast;
	t_stack	*last;

	blast = *a;
	while (blast->next->next)
		blast = blast->next;
	last = ft_lstlast(*a);
	blast->next = NULL;
	last->next = *a;
	*a = last;
}

void	rev_retating(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
	{
		rev_retate(a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		rev_retate(b);
		write(1, "rra\n", 4);
	}
	else if (c == 't')
	{
		rev_retate(a);
		rev_retate(b);
		write(1, "rrr\n", 4);
	}
}
