/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:22 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:09:22 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *begin_list, void (*f)(void *))
{
	if (!begin_list)
		return ;
	(*f)(begin_list->content);
	while (begin_list->next)
	{
		(*f)(begin_list->next->content);
		begin_list = begin_list->next;
	}
}
