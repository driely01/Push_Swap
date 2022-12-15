/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:54 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/15 15:25:38 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words_count(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		j = 1;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (j == 1)
			{
				n++;
				j = 0;
			}
			i++;
		}
	}
	return (n);
}

static	char	**ft_free(char **str, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
		free(str[i++]);
	free(str);
	return (NULL);
}

static char	**ft_handler(char const *s, char **str, char c, int start)
{
	size_t	j;
	size_t	i;
	int		finish;

	i = -1;
	j = 0;
	finish = -1;
	while (s[++i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if ((s[i] != c && finish == -1 && s[i + 1] == c) || s[i + 1] == '\0')
			finish = i + 1;
		if (start != -1 && finish != -1)
		{
			str[j] = ft_substr(s, start, finish - start);
			if (!str[j])
				return (ft_free(str, j));
			j++;
			start = -1;
			finish = -1;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;

	if (!s)
		return (0);
	start = -1;
	str = (char **)malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (!str)
		return (0);
	return (ft_handler(s, str, c, start));
}
