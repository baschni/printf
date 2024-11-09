/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_spec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:04:39 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/24 11:04:39 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SPEC_BONUS_H
# define T_SPEC_BONUS_H

typedef struct t_spec
{
	char	*str;
	char	conv;
	char	padding;
	char	sign;
	char	alternate;
	int		width;
	int		precision;
	char	precision_padding;
}	t_spec;

typedef struct s_spec_list
{
	t_spec				*content;
	struct s_spec_list	*next;
}	t_spec_list;

#endif