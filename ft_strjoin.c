/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:59:41 by del-yaag          #+#    #+#             */
/*   Updated: 2022/12/15 15:23:08 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(size_t size, char **strs, char *sep)
{
	size_t	new_length;
	char	*new_string;
	size_t	i;

	if (size <= 0)
		return (NULL);
	i = -1;
	new_length = ft_strlen(sep) * (size - 1);
	while (++i < size)
		new_length += ft_strlen(strs[i]);
	new_length++;
	new_string = malloc(sizeof(char) * new_length);
	if (!(new_string))
		return (NULL);
	ft_strcpy(new_string, strs[0]);
	i = 0;
	while (++i < size)
	{
		ft_strcat(new_string, sep);
		ft_strcat(new_string, strs[i]);
	}
	return (new_string);
}
