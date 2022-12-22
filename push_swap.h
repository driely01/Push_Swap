/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:08:04 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/21 19:09:26 by del-yaag         ###   ########.fr       */
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

size_t		ft_strlen(const char *str);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
long long	ft_atoi(const char *str);
void		swap_all(t_stack **a);
void		swaping(t_stack **a, t_stack **b, char c);
void		push_all(t_stack **a, t_stack **b);
void		pushing(t_stack **a, t_stack **b, char c);
void		retate_all(t_stack **a);
void		retating(t_stack **a, t_stack **b, char c);
void		rev_retate(t_stack **a);
void		rev_retating(t_stack **a, t_stack **b, char c);
char		*ft_strjoin(size_t size, char **strs, char *sep);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			check_num(int argc, char **argv);
void		add_node(t_stack **a, char **argv, int size);
// int			sorted(t_stack *a);
int			r_indexes(t_stack **a, t_stack **b, int num, int real);
void		ret_rev_b(t_stack **a, t_stack **b, int i, int num);
void		check_smaller(t_stack **a, t_stack **b);
void		push_2a(t_stack **a, t_stack **b, int i, int j);
void		push_2b(t_stack **a, t_stack **b);
int			check_closer(int ind1, int ind2, int length);
int			find_node(t_stack *b, int in);
int			division_num(t_stack **stack);
void		give_indexs(t_stack **a, int i, int min);
void		min_index(t_stack **a);

#endif
