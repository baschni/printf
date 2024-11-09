/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:09:32 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:09:32 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstadd_back(t_list **begin_list, t_list *new)
{
	if (*begin_list == NULL)
		*begin_list = new;
	else
		ft_lstlast(*begin_list)->next = new;
}
