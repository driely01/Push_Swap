/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_free_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:58:33 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/25 21:59:29 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

void	fill_node(t_stack **a, t_stack **top, char **splited)
{
	size_t	i;

	i = 0;
	while (splited[++i])
	{
		if (!(*a))
		{
			*a = malloc(sizeof(t_stack));
			*top = *a;
		}
		else
		{
			(*a)->next = malloc(sizeof(t_stack));
			*a = (*a)->next;
		}
		if (!(*a))
		{
			ft_lstclear(a);
			return ;
		}
		(*a)->data = (int)ft_atoi(splited[i], NULL);
		(*a)->index = -1;
	}
}

void	add_node(t_stack **a, char **argv, int argc)
{
	char	*joined;
	char	**splited;
	t_stack	*top;

	joined = ft_strjoin(argc, argv, " ");
	splited = ft_split(joined, ' ');
	free(joined);
	fill_node(a, &top, splited);
	ft_free(splited);
	(*a)->next = NULL;
	*a = top;
}
