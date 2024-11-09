/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_str_char_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:32 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:09:15 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "null_str.h"
#include "t_spec_bonus.h"

int	ft_printf_putchar_n(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (write(STDOUT_FILENO, &c, 1) < 0)
			return (-1);
		i++;
	}
	return (n);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (write(STDOUT_FILENO, str, 1) < 0)
			return (-1);
		i++;
		str++;
	}
	return (i);
}

int	ft_putnstr(char *str, int n)
{
	int	i;

	if (!str)
		return (ft_putstr(LINUX_OUTPUT_STR_NULL));
	i = 0;
	while (*str && i < n)
	{
		if (write(STDOUT_FILENO, str, 1) < 0)
			return (-1);
		i++;
		str++;
	}
	return (i);
}

int	ft_printf_putnstr_inner(t_spec *spec, char *str)
{
	if (!str)
		str = OSX_OUTPUT_STR_NULL;
	if (spec->precision >= 0 && ((int) ft_strlen(str) > spec->precision))
		return (ft_putnstr(str, spec->precision));
	else
		return (ft_putstr(str));
}

int	ft_printf_putstr(t_spec *spec, char *str)
{
	int	len;
	int	ret;

	len = 0;
	if (!str && __ON_LINUX)
	{
		if (spec->precision >= 0 \
		&& (int) ft_strlen(LINUX_OUTPUT_STR_NULL) > spec->precision)
			ret = 0;
		else
		{
			ret = ft_putstr(LINUX_OUTPUT_STR_NULL);
			if (ret < 0)
				return (-1);
		}
		len += ret;
	}
	else
	{
		ret = ft_printf_putnstr_inner(spec, str);
		if (ret < 0)
			return (-1);
		len += ret;
	}
	return (len);
}
