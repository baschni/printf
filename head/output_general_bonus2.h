/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_general_bonus2.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:08:07 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:06:11 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_GENERAL_BONUS2_H
# define OUTPUT_GENERAL_BONUS2_H

# include <stdint.h>

# include "t_arg_bonus.h"
# include "t_spec_bonus.h"

int	max(int a, int b);
int	ft_printf_putchar(char c);
int	print_padding(t_spec *spec, t_arg *arg, int delta_zero, int len);

#endif
