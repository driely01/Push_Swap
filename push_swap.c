/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:07:52 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/20 18:23:04 by del-yaag         ###   ########.fr       */
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

void	r_indexes(t_stack **a, t_stack **b, int num, int real)
{
	t_stack	*last;
	
	last = *b;
	if ((last->index >= num - real) && (last->index < num - (real / 2)))
		retating(a, b, 'b');
	else
		return ;
}

int	division_num(t_stack **stack)
{
	int	num;
	
	if (ft_lstsize(*stack) >= 5 && ft_lstsize(*stack) <= 100)
		num = ft_lstsize(*stack) / 5;
	else if (ft_lstsize(*stack) > 100 && ft_lstsize(*stack) <= 500)
		num = ft_lstsize(*stack) / 10;
	
	return (num);
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

int check_closer(int ind1, int ind2, int length)
{
	if (ind1 <= length / 2)
		ind1 = ind1;
	else
		ind1 = length - ind1;

	if (ind2 <= length / 2)
		ind2 = ind2;
	else
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

void check_smaller(t_stack **a, t_stack **b)
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

void ret_rev_b(t_stack **a, t_stack **b, int i, int num)
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

void	push_2a(t_stack **a, t_stack **b)
{
	int 	num;
	int		i;
	int		j;
	
	// while (*b)
	// {
	// 	num = ft_lstsize(*b) - 1;
	// 	i = find_node(*a, *b, num);
	// 	j = find_node(*a, *b, num - 1);
	// 	// if (i == 0 || j == 0)
	// 	// {
	// 	// 	pushing(a, b, 'b');
	// 	// 	printf("pushine achriif!!!");	
	// 	// }
	// 	// else
	// 	// {
	// 		while (i != -1 || j != -1)
	// 		{
	// 			if (i == -1 && j == -1)
	// 				break;
	// 			i = find_node(*a, *b, num);
	// 			// j = find_node(*a, *b, num - 1);
	// 			if ((i != -1 && check_closer(i, j, num) == 0) || j == -1)
	// 			{
	// 				ret_rev_b(a, b, i, num);
	// 				pushing(a, b, 'b');
	// 				num = ft_lstsize(*b) - 1;
	// 				j = find_node(*a, *b, num);
	// 				i = -1;
	// 			}
	// 			else if ((j != -1 && check_closer(i, j, num) == 1) || i == -1)
	// 			{
	// 				ret_rev_b(a, b, j, num);
	// 				pushing(a, b, 'b');
	// 				j = -1;
	// 			}
	// 		}
	// 		// break ;
	// 	// }
	// }

	j = -1;
	i = -1;
	while (*b)
	{
		if (i == - 1 && j == -1)
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
// void	push_2a(t_stack **a, t_stack **b)
// {
// 	t_stack	*top;
// 	int 	num;
// 	int		i;
// 	int		j;
	
// 	while (*b)
// 	{
// 		if (ft_lstsize(*b) >= 2)
// 		{	
// 			num = ft_lstsize(*b) - 1;
// 			i = find_node(*a, *b, num);
// 			if ((*b)->index == num)
// 			{
// 				pushing(a, b, 'b');
// 				check_smaller(a, b);
// 			}
// 			else
// 				ret_rev_b(a, b, &i, num);
// 		}
// 		else
// 		{
// 			pushing(a, b, 'b');
// 			check_smaller(a, b);
// 		}
// 	}
// }

// void	push_2a(t_stack **a, t_stack **b)
// {
// 	t_stack	*top;
// 	int 	num;
// 	int		i;
// 	int		j;

// 	while (*b)
// 	{
// 		// top = *b;
// 		num = ft_lstsize(*b) - 1;
// 		if (num >= 2)
// 		{	
// 			i = find_node(*a, *b, num);
// 			j = find_node(*a, *b, num - 1);
// 			if ((*b)->index == num - 1 || (*b)->index == num - 2)
// 			{
// 				pushing(a, b, 'b');
// 				check_smaller(a, b);
// 			}
// 			else
// 			{
// 				if (check_closer(i, j, num - 1) == 0)
// 				{	
// 					if (i <= num / 2)
// 					{
// 						while (i >= 0)
// 						{
// 							retating(a, b, 'b');
// 							i--;
// 						}
// 					}
// 					else
// 					{
// 						while (i <= num)
// 						{
// 							rev_retating(a, b, 'b');
// 							i++;
// 						}
// 					}
// 				}
// 				else
// 				{
// 					if (j <= num / 2)
// 					{
// 						while (j >= 0)
// 						{
// 							retating(a, b, 'b');
// 							j--;
// 						}
// 					}
// 					else
// 					{
// 						while (j <= num)
// 						{
// 							rev_retating(a, b, 'b');
// 							j++;
// 						}
// 					}
// 				}
// 			}
// 		}
// 		else
// 		{
// 			pushing(a, b, 'b');
// 			check_smaller(a, b);
// 		}	
// 	}
// }

// void	push_2a(t_stack **a, t_stack **b)
// {
// 	t_stack	*top;
// 	int 	num;
// 	int		i;
// 	int		j;

// 	num = ft_lstsize(*b);
// 	i = find_node(*a, *b, num - 1);
// 	printf("%d\n", check_closer(i, j, num));
// 	while (*b)
// 	{
// 		num = ft_lstsize(*b);
// 		i = find_node(*a, *b, num - 1);
// 		if ((*b)->index == num - 1)
// 			pushing(a, b, 'b');
// 		else
// 		{
// 			if (i < num / 2)
// 			{
// 				while (i >= 0)
// 				{
// 					retating(a, b, 'b');
// 					i--;
// 				}
// 			}
// 			else
// 			{
// 				while (i < num)
// 				{
// 					rev_retating(a, b, 'b');
// 					i++;
// 				}
// 			}
// 		}
// 	}
// }

// void	push_2bb(t_stack **a, t_stack **b)
// {
// 	t_stack	*top;
// 	int 	num;
// 	int		i;
// 	int		j;

// 	num = ft_lstsize(*a);
// 	i = find_node(*b, *a, num - 1);
// 	while (*a)
// 	{
// 		num = ft_lstsize(*a);
// 		i = find_node(*b, *a, num - 1);
// 		if ((*a)->index == num - 1)
// 			pushing(a, b, 'a');
// 		else
// 		{
// 			if (i < num / 2)
// 			{
// 				while (i > 0)
// 				{
// 					retating(a, b, 'b');
// 					i--;
// 				}
// 			}
// 			else
// 			{
// 				while (i < num)
// 				{
// 					rev_retating(a, b, 'b');
// 					i++;
// 				}
// 			}
// 		}
// 	}
// }

void	push_2b(t_stack **a, t_stack **b)
{
	int		num;
	size_t	real;
	size_t	i;

	i = 0;
	num = division_num(a);
	real = num;
	while (*a)
	{
		if ((*a)->index < num)
		{
			pushing(a, b, 'a');
			if (ft_lstsize(*b) >= 2)
				r_indexes(a, b, num, real);
		}
		else
			retating(a, b, 'a');
		if (ft_lstsize(*b) == num)
			num += real;
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
			min_index(&a);
			push_2b(&a, &b);
			// h = b;
			// while (h)
			// {
			// 	printf("%d\t---->\t%d\n", h->data, h->index);
			// 	h = h->next;
			// }
			push_2a(&a, &b);
			// h = a;
			// while (h)
			// {
			// 	printf("%d\t---->\t%d\n", h->data, h->index);
			// 	h = h->next;
			// }
			// find_node(a, b, 466);
		}
	}
	return (0);
}
