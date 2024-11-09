/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:48 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:09:48 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		len_little;

	len_little = ft_strlen(little);
	if (!*little)
		return ((char *) big);
	while (*big && len >= len_little)
	{
		b = big;
		l = little;
		while (*b && *l == *b)
		{
			b++;
			l++;
		}
		if (!*l)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
