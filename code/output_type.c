/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:35 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/22 17:59:35 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#include "libft.h"
#include "null_str.h"
#include "t_spec.h"
#include "output_general.h"

int	ft_printf_char(char c)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_printf_putstr(LINUX_OUTPUT_STR_NULL));
	i = 0;
	while (*str)
	{
		if (write(STDOUT_FILENO, str, 1) == -1)
			return (-1);
		i++;
		str++;
	}
	return (i);
}

int	ft_print_hex(uintptr_t nbr, char upper_or_lower)
{
	int		remainder;	
	char	out;
	int		written;

	written = 0;
	if (nbr / 16 != 0)
	{
		remainder = ft_print_hex(nbr / 16, upper_or_lower);
		if (remainder == -1)
			return (-1);
		written += remainder;
	}
	remainder = nbr % 16;
	if (remainder < 10)
		out = '0' + remainder;
	else
		out = upper_or_lower - 'x' + 'a' + remainder - 10;
	if (write(1, &out, 1) == -1)
		return (-1);
	return (written + 1);
}

int	ft_printf_unsigned_int(t_spec *spec, uintptr_t n)
{
	int		written;
	int		ret;

	written = 0;
	if (n >= 10)
	{
		ret = ft_printf_unsigned_int(spec, n / 10);
		if (ret == -1)
			return (-1);
		written += ret;
	}
	if (ft_printf_char('0' + n % 10) == -1)
		return (-1);
	written++;
	return (written);
}

int	ft_printf_pointer(t_spec *spec, void *ptr)
{
	int	ret;

	(void) spec;
	if (!ptr)
	{
		if (__ON_LINUX)
			return (ft_printf_putstr(LINUX_OUTPUT_PTR_NULL));
		else
			return (ft_printf_putstr(OSX_OUTPUT_PTR_NULL));
	}
	if (ft_printf_putstr("0x") == -1)
		return (-1);
	ret = ft_print_hex((uintptr_t) ptr, 'x');
	if (ret == -1)
		return (-1);
	return (2 + ret);
}
