/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:21 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 20:49:29 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_stack	*ft_lstlast(t_stack *lst)
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

	if (ft_lstsize(*a) <= 1)
		return ;
	head = (*a)->next;
	last = ft_lstlast(*a);
	last->next = *a;
	last->next->next = NULL;
	*a = head;
}

void	retating(t_stack **a, t_stack **b, char c)
{
	if (c == 'a')
		retate_all(a);
	else if (c == 'b')
		retate_all(b);
	else if (c == 't')
	{
		retate_all(a);
		retate_all(b);
	}
}

void	rev_retate(t_stack **a)
{
	t_stack	*blast;
	t_stack	*last;

	if (ft_lstsize(*a) <= 1)
		return ;
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
		rev_retate(a);
	else if (c == 'b')
		rev_retate(b);
	else if (c == 't')
	{
		rev_retate(a);
		rev_retate(b);
	}
}
