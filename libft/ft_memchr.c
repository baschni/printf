/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:10:28 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:10:28 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	a;
	size_t			i;

	a = (unsigned char) c;
	i = 0;
	t = (unsigned char *) s;
	while (i < n)
	{
		if (a == *t)
			return (t);
		t++;
		i++;
	}
	return (NULL);
}
