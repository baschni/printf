/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_str_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:40 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 03:14:03 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "t_spec_bonus.h"
#include "libft.h"
#include "null_str.h"

void	parse_flag_char(char c, t_spec *spec)
{
	if (c == ' ' && spec->sign != '+')
		spec->sign = ' ';
	else if (c == '+')
		spec->sign = '+';
	else if (c == '#')
		spec->alternate = 1;
	else if (c == '0' && spec->padding != '-')
		spec->padding = '0';
	else if (c == '-')
		spec->padding = '-';
}

void	adjust_precision_and_padding(char *i, t_spec *spec)
{
	char	*prec;

	prec = ft_strchr(i, '.');
	if (prec)
	{
		if (*(prec + 1) == '-')
		{
			spec->width = 0;
			spec->precision_padding = ' ';
			prec++;
		}
		spec->precision = ft_atoi(prec + 1);
	}
	if (spec->padding == ' ' && spec->width == -1 && spec->precision == -1)
		spec->width = 2;
	if (spec->padding != '-' && spec->precision >= 0 && __ON_LINUX)
		spec->padding = ' ';
}

void	parse_spec(void *vspec)
{
	t_spec	*spec;
	char	*i;
	char	*last;

	spec = (t_spec *) vspec;
	if (spec->conv == 'l')
		return ;
	i = spec->str;
	last = i + ft_strlen(spec->str) - 1;
	spec->conv = *(last);
	while (*i == '0' || (!ft_isdigit(*i) && *i != '.' && i != last))
	{
		parse_flag_char(*i, spec);
		i++;
	}
	if (i == last)
		return ;
	if (ft_isdigit(*i))
		spec->width = ft_atoi(i);
	adjust_precision_and_padding(i, spec);
}
