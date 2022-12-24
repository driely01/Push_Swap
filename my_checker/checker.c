/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:37:55 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/24 15:42:21 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static void	checker_func(t_stack **a, t_stack **b, int argc, char **argv)
{
	add_node(a, argv, argc);
	do_instractions(a, b);
	if (sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(a);
	ft_lstclear(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	b = NULL;
	a = NULL;
	if (argc > 1)
	{
		if (check_num(argc, argv) == 0)
			exit(0);
		else
			checker_func(&a, &b, argc, argv);
	}
	return (0);
}
