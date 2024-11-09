/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_length_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:24:13 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:08:19 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"
#include "null_str.h"
#include "t_spec_bonus.h"
#include "t_arg_bonus.h"
#include "output_general_bonus2.h"

static int	inner_length_empty_ptr(t_spec *spec)
{
	if (__ON_LINUX)
		return (ft_strlen(LINUX_OUTPUT_PTR_NULL));
	if (spec->precision != 0)
		return (1);
	return (0);
}

static int	inner_length_char_str(t_spec *spec, t_arg *arg)
{
	if (spec->conv == 'c')
		return (1);
	else if (spec->conv == 's')
	{
		if (!arg->s)
		{
			if (spec->precision >= 0 && \
			(int) ft_strlen(LINUX_OUTPUT_STR_NULL) > spec->precision)
				return (0);
			else
				return (ft_strlen(LINUX_OUTPUT_STR_NULL));
		}
		if (spec->precision >= 0 && \
		(int) ft_strlen(arg->s) > spec->precision)
			return (spec->precision);
	}
	return (ft_strlen(arg->s));
}

static int	get_digits(t_spec *spec, uintptr_t n, uintptr_t base)
{
	int	digits;

	if (spec->conv != 'p' && n == 0 && spec->precision == 0)
		return (0);
	digits = 1;
	while (n / base != 0)
	{
		n = n / base;
		digits++;
	}
	return (digits);
}

static int	get_inner_length(t_spec *spec, t_arg *arg)
{
	intptr_t	nbr;
	int			base;

	if (spec->conv == 'c' || spec->conv == 's')
		return (inner_length_char_str(spec, arg));
	if (spec->conv == 'x' || spec->conv == 'X' || spec->conv == 'p')
		base = 16;
	else
		base = 10;
	if (spec->conv == 'u' || spec->conv == 'x' || spec->conv == 'X')
		nbr = arg->u;
	else if (spec->conv == 'p')
	{
		if (!arg->p)
			return (inner_length_empty_ptr(spec));
		nbr = (uintptr_t) arg->p;
	}
	else
	{
		nbr = (intptr_t) arg->i;
		nbr = nbr * (1 - 2 * (nbr < 0));
	}
	return (get_digits(spec, nbr, base));
}

int	write_left_padding(t_spec *spec, t_arg *arg)
{
	int	delta_zero;
	int	len;

	len = get_inner_length(spec, arg);
	delta_zero = max(spec->precision - len, 0);
	if ((spec->conv == 's' || spec->conv == 'c') && !__ON_LINUX)
	{
		if (spec->padding == '0')
			delta_zero = max(spec->width - len, 0);
		else
			delta_zero = 0;
	}
	if ((spec->conv == 's' && __ON_LINUX) || (spec->conv == 'c' && \
	__ON_LINUX) || (spec->conv == 'p' && arg->p == NULL && __ON_LINUX))
	{
		delta_zero = 0;
		if (spec->padding == '0')
			spec->padding = ' ';
	}
	return (print_padding(spec, arg, delta_zero, len));
}
