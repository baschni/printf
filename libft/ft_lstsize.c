/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:08:17 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:08:17 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int	count;

	if (!begin_list)
		return (0);
	count = 1;
	while (begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
