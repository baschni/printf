/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:10:19 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:10:19 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;
	int		step;

	if (!dest && !src)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	i = 0;
	step = 1;
	if (dest > src)
	{
		step = (-1);
		d = d + n - 1;
		s = s + n - 1;
	}
	while (i < n)
	{
		*d = *s;
		d += step;
		s += step;
		i++;
	}
	return (dest);
}
