/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex_int_ptr_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:08:27 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/13 20:08:34 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_HEX_INT_PTR_BONUS_H
# define OUTPUT_HEX_INT_PTR_BONUS_H

int	ft_printf_int(t_spec *spec, int n);
int	ft_printf_pointer(t_spec *spec, void *ptr);
int	ft_printf_unsigned_int(t_spec *spec, unsigned int n);

#endif
