/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:38:12 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/09 20:38:12 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ARG_BONUS_H
# define T_ARG_BONUS_H

typedef struct t_arg
{
	char			*s;
	char			c;
	int				i;
	unsigned int	u;
	void			*p;
}	t_arg;

#endif