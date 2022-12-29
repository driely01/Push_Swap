/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:29:23 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/29 12:31:01 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct collecion{
	int		r;
	size_t	i;
	char	*bf;
	char	*ln;
}	t_collecion;

typedef struct s_stack
{
	int				index;
	int				data;
	struct s_stack	*next;
}	t_stack;

# define BUFFER_SIZE 1

// get next line
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t number, size_t size);
char	*cpy(char *s, char *p);
char	*ft_append(char *s1, char *s2);
char	*ft_read(char **leftover, char *line, size_t i);
char	*get_next_line(int fd);
char	*cpy_two(char *s1, char *s2, char *p);
int		stc(t_collecion *vb);

// rules
int		ft_lstsize(t_stack *lst);
void	swap_all(t_stack **a);
void	swaping(t_stack **a, t_stack **b, char c);
void	push_all(t_stack **a, t_stack **b);
void	pushing(t_stack **a, t_stack **b, char c);
void	retate_all(t_stack **a);
void	retating(t_stack **a, t_stack **b, char c);
void	rev_retate(t_stack **a);
void	rev_retating(t_stack **a, t_stack **b, char c);

//parsing
int		check_num(int argc, char **argv);
long	ft_atoi(char *str);
char	*ft_strjoin(size_t size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	add_node(t_stack **a, char **argv, int size);
void	checker_parsing(char *line, char *ptr, t_stack **a, t_stack **b);
int		ft_strcmp(char *s1, char *s2);
int		sorted(t_stack *a);
int		check_spaces(char **str);
int		find_spaces(char *str);

//fill & free
char	**ft_free(char **str);
void	ft_lstclear(t_stack **lst);
void	add_node(t_stack **a, char **argv, int argc);
void	fill_node(t_stack **a, t_stack **top, char **splited);

//instraction application
void	do_instractions(t_stack **a, t_stack **b);

#endif