/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:10:10 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:10:10 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char) c;
	while (*s)
	{
		if (a == *s)
			return ((char *) s);
		s++;
	}
	if (!*s && a == '\0')
		return ((char *) s);
	return (NULL);
}
