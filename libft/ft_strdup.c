/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:10:07 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:10:07 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*start;

	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	start = dup;
	if (!dup)
		return (NULL);
	while (*s)
	{
		*dup = *s;
		s++;
		dup++;
	}
	*dup = '\0';
	return (start);
}
