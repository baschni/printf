/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:38:33 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/09 20:38:33 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_TYPE_H
# define OUTPUT_TYPE_H

# include <stdint.h>

int	ft_printf_char(char c);
int	ft_printf_putstr(char *str);
int	ft_print_hex(uintptr_t nbr, char upper_or_lower);
int	ft_printf_unsigned_int(t_spec *spec, unsigned int n);
int	ft_printf_pointer(t_spec *spec, void *ptr);

#endif