/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_spec_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:34:11 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:40:52 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_SPEC_BONUS_H
# define FREE_SPEC_BONUS_H

# include "t_spec_bonus.h"

void	free_spec(void *vspec);
void	free_specs(t_spec_list **specs);

#endif