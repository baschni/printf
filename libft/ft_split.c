/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:10:14 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/28 02:50:38 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_count_splits(char **split)
{
	size_t	len;

	len = 0;
	while (*split)
	{
		len++;
		split++;
	}
	return (len);
}

void	*ft_free_splits(void *vtable)
{
	char	**table;
	char	**temp;

	table = (char **) vtable;
	temp = table;
	while (*table)
	{
		free(*table);
		table++;
	}
	free(temp);
	return (NULL);
}

static size_t	posstrchr(char const *s, char c)
{
	size_t	i;

	s++;
	i = 1;
	while (*s)
	{
		if (*s == c)
			return (i);
		i++;
		s++;
	}
	return (0);
}

char	**get_splits(char const **s, char c, char **table, char **start)
{
	size_t	len;
	char	*split;

	if (**s != c)
	{
		len = posstrchr(*s, c);
		if (posstrchr(*s, c) == 0)
			len = ft_strlen(*s);
		split = ft_substr(*s, 0, len);
		*s += len - 1;
		*table = split;
		if (*(table++) == NULL)
			return (ft_free_splits(start));
	}
	return (table);
}

char	**ft_split(char const *s, char c)
{
	char		**table;
	char		**start;
	size_t		splits;
	const char	*sstart;

	splits = 0;
	sstart = s;
	s = s - 1;
	while (*(++s))
		if (*s != c && (s == sstart || *(s - 1) == c))
			splits++;
	s = sstart;
	table = malloc(sizeof(char *) * (splits + 1));
	if (table == NULL)
		return (NULL);
	start = table;
	while (*s)
	{
		table = get_splits(&s, c, table, start);
		if (!table)
			return (NULL);
		s++;
	}
	*table = NULL;
	return (start);
}
