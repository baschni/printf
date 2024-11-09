/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:42 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:09:42 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		total;
	char		*target;
	const char	*begin;

	if (!set || !s1)
		return ((char *) s1);
	begin = s1;
	total = ft_strlen(s1);
	start = 0;
	while (*s1 && ft_strchr(set, *s1))
	{
		start++;
		s1++;
	}
	end = 0;
	s1 = begin + total - 1;
	while (end < total && *s1 && ft_strchr(set, *s1))
	{
		end++;
		s1--;
	}
	target = ft_substr(begin, start, total - end - start);
	return (target);
}
