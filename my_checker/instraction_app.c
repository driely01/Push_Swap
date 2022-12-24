/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_app.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:00:08 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/24 14:01:57 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	error_handling(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

static void	instraction(t_stack **a, t_stack **b, char *inst)
{
	if (!ft_strcmp(inst, "sa"))
		swaping(a, b, 'a');
	else if (!ft_strcmp(inst, "sb"))
		swaping(a, b, 'b');
	else if (!ft_strcmp(inst, "ss"))
		swaping(a, b, 't');
	else if (!ft_strcmp(inst, "ra"))
		retating(a, b, 'a');
	else if (!ft_strcmp(inst, "rb"))
		retating(a, b, 'b');
	else if (!ft_strcmp(inst, "rr"))
		retating(a, b, 't');
	else if (!ft_strcmp(inst, "rra"))
		rev_retating(a, b, 'a');
	else if (!ft_strcmp(inst, "rrb"))
		rev_retating(a, b, 'b');
	else if (!ft_strcmp(inst, "rrr"))
		rev_retating(a, b, 't');
	else if (!ft_strcmp(inst, "pa"))
		pushing(a, b, 'b');
	else if (!ft_strcmp(inst, "pb"))
		pushing(a, b, 'a');
	else
		error_handling();
}

void	do_instractions(t_stack **a, t_stack **b)
{
	char	*inst;
	char	*joined;
	char	**splited;
	int		i;

	inst = get_next_line(0);
	joined = NULL;
	i = 0;
	while (inst)
	{
		checker_parsing(inst, joined);
		joined = ft_append(joined, inst);
		free(inst);
		inst = get_next_line(0);
	}
	splited = ft_split(joined, '\n');
	free(joined);
	while (splited[i])
	{
		instraction(a, b, splited[i]);
		i++;
	}
	ft_free(splited);
}
