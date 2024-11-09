/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:30 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/22 17:59:30 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "t_spec.h"
#include "output_type.h"

static int	ft_printf_int(t_spec *spec, int n)
{
	int		written;
	char	c;
	int		ret;

	written = 0;
	ret = 0;
	if (n < 0)
	{
		c = '-';
		if (write(STDOUT_FILENO, &c, 1) == -1)
			return (-1);
		written++;
	}
	if (n / 10 != 0)
		ret = ft_printf_unsigned_int(spec, n / 10 * (1 - 2 * (n < 0)));
	if (ret == -1)
		return (-1);
	written += ret;
	c = (n % 10) * (1 - 2 * (n < 0)) + '0';
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (-1);
	written++;
	return (written);
}

int	output_conversions(t_spec *spec, va_list args)
{
	if (spec->conv == 'l')
		return (ft_printf_putstr(spec->str));
	else if (spec->conv == 'c')
		return (ft_printf_char((char) va_arg(args, int)));
	else if (spec->conv == '%')
		return (ft_printf_char('%'));
	else if (spec->conv == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	else if (spec->conv == 'x' || spec->conv == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), spec->conv));
	else if (spec->conv == 'u')
		return (ft_printf_unsigned_int(spec, va_arg(args, unsigned int)));
	else if (spec->conv == 'd' || spec->conv == 'i')
		return (ft_printf_int(spec, va_arg(args, int)));
	else if (spec->conv == 'p')
		return (ft_printf_pointer(spec, va_arg(args, void *)));
	return (0);
}
