/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str_char_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:08:38 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/13 20:08:54 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_STR_CHAR_BONUS_H
# define OUTPUT_STR_CHAR_BONUS_H

int	ft_printf_putchar_n(char c, int n);
int	ft_printf_putstr(t_spec *spec, char *str);
int	ft_putstr(char *str);
int	ft_putnstr(char *str, int n);

#endif
