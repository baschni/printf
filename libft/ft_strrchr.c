/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:44 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:09:44 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*start ;
	unsigned char	a;

	a = (unsigned char) c;
	start = s;
	s = s + ft_strlen(s) + 1;
	while (--s >= start)
		if (a == *s)
			return ((char *) s);
	return (NULL);
}
