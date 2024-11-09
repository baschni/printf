/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_general_bonus2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:48:49 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:09:07 by basc`hnit         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#include "libft.h"
#include "null_str.h"
#include "t_spec_bonus.h"
#include "t_arg_bonus.h"
#include "output_str_char_bonus.h"

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

static char	get_sign(t_arg *arg, t_spec *spec)
{
	char	conv;
	char	sign;

	conv = spec->conv;
	sign = 0;
	if (spec->sign == '+')
		if (conv == 'd' || conv == 'i' || (conv == 'p' && arg->p && __ON_LINUX))
			sign = '+';
	if (spec->sign == ' ')
		if (conv == 'd' || conv == 'i' || (conv == 'p' && arg->p && __ON_LINUX))
			sign = ' ';
	if ((conv == 'd' || conv == 'i') && arg->i < 0)
		sign = '-';
	return (sign);
}

int	ft_printf_putchar(char c)
{
	if (write(STDOUT_FILENO, &c, 1) < 0)
		return (-1);
	return (1);
}

int	print_sign_and_prefix(int sign, int prefix, char conv)
{
	if (sign)
		if (ft_printf_putchar(sign) == -1)
			return (-1);
	if (prefix && conv == 'X')
		if (ft_putstr("0X") == -1)
			return (-1);
	if (prefix && conv != 'X')
		if (ft_putstr("0x") == -1)
			return (-1);
	return (0);
}

int	print_padding(t_spec *spec, t_arg *arg, int delta_zero, int len)
{
	int	delta;
	int	sign;
	int	prefix;

	sign = get_sign(arg, spec);
	prefix = (((spec->conv == 'x' || spec->conv == 'X') && spec->alternate && \
	arg->u != 0) || (spec->conv == 'p' && (arg->p != NULL || !__ON_LINUX))) * 2;
	delta = max(spec->width - delta_zero - len - (sign != 0) - prefix, 0);
	if (spec->padding == '-')
		delta = 0;
	if (spec->padding != '0' || (!__ON_LINUX && spec->precision != -1) \
	|| (__ON_LINUX && spec->conv == 'p' && arg->p == NULL))
		if (ft_printf_putchar_n(' ', delta) == -1)
			return (-1);
	if (print_sign_and_prefix(sign, prefix, spec->conv) == -1)
		return (-1);
	if (ft_printf_putchar_n(spec->precision_padding, delta_zero) == -1)
		return (-1);
	if (spec->padding == '0' && !(spec->conv == 'p' && arg->p == NULL && \
	__ON_LINUX) && !(!__ON_LINUX && spec->precision != -1))
		if (ft_printf_putchar_n('0', delta) == -1)
			return (-1);
	return (delta + delta_zero + prefix + (sign != 0));
}
