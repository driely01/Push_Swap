/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 14:03:51 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/15 15:39:04 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t number, size_t size)
{
	void	*p;
	int		i;

	i = number * size;
	if ((number && (i / number) != size) || (size && (i / size) != number))
		return (NULL);
	p = malloc(i);
	if (!p)
		return (0);
	ft_bzero(p, number * size);
	return (p);
}

static void	*ft_cpy(char *p, char const *s2, unsigned int start, size_t l)
{
	size_t	i;

	i = 0;
	if (!p)
		return (0);
	while (i < l)
	{
		p[i] = s2[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	x;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start <= ft_strlen(s))
	{
		x = ft_strlen(s) - start;
		if (len <= x)
		{
			p = malloc(sizeof(char) * len + 1);
			ft_cpy(p, s, start, len);
		}
		else
		{
			p = malloc(sizeof(char) * x + 1);
			ft_cpy(p, s, start, x);
		}
	}
	else
		p = (char *)ft_calloc(1, 1);
	return (p);
}
