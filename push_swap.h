/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:08:04 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/24 17:37:53 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack
{
	int				index;
	int				data;
	struct s_stack	*next;
}	t_stack;

size_t	ft_strlen(const char *str);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **lst);

// start rules
int		ft_lstsize(t_stack *lst);
void	swap_all(t_stack **a);
void	swaping(t_stack **a, t_stack **b, char c);
void	push_all(t_stack **a, t_stack **b);
void	pushing(t_stack **a, t_stack **b, char c);
void	retate_all(t_stack **a);
void	retating(t_stack **a, t_stack **b, char c);
void	rev_retate(t_stack **a);
void	rev_retating(t_stack **a, t_stack **b, char c);
// end rules

// start parsing
int		check_num(int argc, char **argv);
long	ft_atoi(const char *str);
char	*ft_strjoin(size_t size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	add_node(t_stack **a, char **argv, int size);
// end parsing

// start chunks list algorithm
int		r_indexes(t_stack **a, t_stack **b, int num, int real);
void	ret_rev_b(t_stack **a, t_stack **b, int i, int num);
void	check_smaller(t_stack **a, t_stack **b);
void	push_2a(t_stack **a, t_stack **b, int i, int j);
void	push_2b(t_stack **a, t_stack **b);
int		check_closer(int ind1, int ind2, int length);
int		find_node(t_stack *b, int in);
int		division_num(t_stack **stack);
void	give_indexs(t_stack **a, int i, int min);
void	min_index(t_stack **a);
// end chunks list algorithm

// start sorting smaller numbers
void	check_cases_three(t_stack **a, int first, int second, int third);
void	sort_three_numbers(t_stack **a);
void	ret_rev_a(t_stack **a, int i, int num);
void	sort_four_numbers(t_stack **a, t_stack **b, int index);
void	ret_rev_a_for_five(t_stack **a, int i);
void	add_node(t_stack **a, char **argv, int argc);
void	sort_five_numbers(t_stack **a, t_stack **b);
void	sort_smaller_numbers(t_stack **a, t_stack **b, int i, int j);
int		sorted(t_stack *a);
// end sorting smaller numbers

//free
char	**ft_free(char **str);

#endif
