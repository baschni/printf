/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_general_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:30 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:08:59 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft.h"
#include "null_str.h"
#include "inner_length_bonus.h"
#include "t_spec_bonus.h"
#include "t_arg_bonus.h"
#include "output_general_bonus2.h"
#include "output_hex_int_ptr_bonus.h"
#include "output_str_char_bonus.h"

static void	init_arg(t_arg *arg, va_list args, t_spec *spec)
{
	arg->s = NULL;
	arg->i = 0;
	if (spec->conv == 'c')
		arg->c = (char) va_arg(args, int);
	else if (spec->conv == 's')
		arg->s = va_arg(args, char *);
	else if (spec->conv == 'x' || spec->conv == 'X' || spec->conv == 'u')
		arg->u = va_arg(args, unsigned int);
	else if (spec->conv == 'd' || spec->conv == 'i')
		arg->i = va_arg(args, int);
	else if (spec->conv == 'p')
		arg->p = va_arg(args, void *);
}

static int	write_right_padding(t_spec *spec, unsigned int len)
{
	int	delta;

	delta = max(spec->width - len, 0);
	if (delta <= 0 || spec->padding != '-')
		return (0);
	if (ft_printf_putchar_n(' ', delta) < 0)
		return (-1);
	return (delta);
}

static int	case_conversions(char conv, t_arg *arg, t_spec *spec)
{
	if (conv == 'c')
		return (ft_printf_putchar(arg->c));
	else if (conv == 's')
		return (ft_printf_putstr(spec, arg->s));
	else if (conv == 'x' || conv == 'X' || conv == 'u')
		return (ft_printf_unsigned_int(spec, arg->u));
	else if (conv == 'p')
		return (ft_printf_pointer(spec, arg->p));
	else if (conv == 'd' || conv == 'i')
		return (ft_printf_int(spec, arg->i));
	return (0);
}

static int	print_conversions(char conv, t_arg *arg, t_spec *spec)
{
	unsigned int	len;
	int				ret;

	len = 0;
	if (conv == 's' && !arg->s && !__ON_LINUX)
		arg->s = OSX_OUTPUT_STR_NULL;
	ret = write_left_padding(spec, arg);
	if (ret < 0)
		return (-1);
	len = ret;
	ret = case_conversions(conv, arg, spec);
	if (ret < 0)
		return (-1);
	len += ret;
	ret = write_right_padding(spec, len);
	if (ret < 0)
		return (-1);
	len += ret;
	return (len);
}

int	output_conversions(t_spec *spec, va_list args)
{
	char	conv;
	t_arg	arg;

	conv = spec->conv;
	if (conv == 'l')
		return (ft_putstr(spec->str));
	if (conv == '%')
	{
		arg.s = "%";
		spec->conv = 's';
		conv = 's';
	}
	else
		init_arg(&arg, args, spec);
	return (print_conversions(conv, &arg, spec));
}
