/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:07:52 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/16 22:27:43 by del-yaag         ###   ########.fr       */
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

static void	give_indexs(t_stack **a, int i, int min)
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

void	push_2b(t_stack **a, t_stack **b)
{
	t_stack	*top;
	int		num;
	int		i;

	i = 1;
	if (ft_lstsize(*a) >= 5 && ft_lstsize(*a) <= 100)
		num = ft_lstsize(*a) / 5;
	printf("num =====> %d\n", num);
	printf("list =====> %zu\n", ft_lstsize(*a));
	while (num)
	{
		top = *a;
		while (top)
		{
			if (top->index <= num)
				pushing(a, b, 'a');
			top = top->next;
		}
		num--;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*h;
	size_t		i;
	char		ptr;

	i = 0;
	if (argc > 1)
	{
		if (check_num(argc, argv) == 0)
			return (1);
		else
		{
			add_node(&a, argv, argc);
			// if (is_sorted(&a))
			// 	return (1);
			h = a;
			while (h)
			{
				printf("%d\t---->\t%d\n", h->data, h->index);
				h = h->next;
			}
			min_index(&a);
			printf("\n\n\n");
			h = a;
			while (h)
			{
				printf("%d\t---->\t%d\n", h->data, h->index);
				h = h->next;
			}
			// push_2b(&a, &b);
			// printf("\n\n\n");
			// h = a;
			// while (h)
			// {
			// 	printf("%d\t---->\t%d\n", h->data, h->index);
			// 	h = h->next;
			// }
			// h = b;
			// while (h)
			// {
			// 	printf("B = %d\t---->\t[%d]\n", h->data, h->index);
			// 	h = h->next;
			// }
			// for (int i = 0; i < 51; i++)
			// 	printf("%d ", i);
		}
	}
	return (0);
}
