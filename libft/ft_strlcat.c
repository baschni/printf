/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:08:28 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:21:26 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	index;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	dest = dest + len_dest;
	index = 0;
	while (index < size - len_dest - 1 && *src && len_dest < size)
	{
		*dest = *src;
		index++;
		src++;
		dest++;
	}
	if (size != 0 && len_dest < size)
		*dest = '\0';
	if (size >= len_dest)
		return (len_dest + len_src);
	else
		return (size + len_src);
}
