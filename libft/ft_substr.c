/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:39 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/31 06:06:20 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	init_max_len(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;

	max_len = ft_strlen(s);
	if (start > max_len)
		max_len = 0;
	else
		max_len = max_len - start;
	if (len < max_len)
		max_len = len;
	return (max_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;
	char	*target;
	char	*begin;

	max_len = init_max_len(s, start, len);
	if (max_len > 0)
		s = s + start;
	target = malloc(sizeof(char) * (max_len + 1));
	if (target == NULL)
		return (NULL);
	begin = target;
	while (*s && max_len > 0)
	{
		*target = *s;
		target++;
		max_len--;
		s++;
	}
	*target = '\0';
	return (begin);
}
