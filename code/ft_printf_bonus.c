/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:33 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:29:56 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "libft.h"
#include "t_spec_bonus.h"
#include "parse_format_str_bonus.h"
#include "split_format_str.h"
#include "output_general_bonus.h"

void	parse_specs(t_spec_list *specs)
{
	ft_lstiter((t_list *) specs, &parse_spec);
}

int	write_output(t_spec_list *specs, va_list args)
{
	int	written_bytes;
	int	total_written_bytes;

	total_written_bytes = 0;
	while (1)
	{
		written_bytes = output_conversions(specs->content, args);
		if (written_bytes == -1)
			return (-1);
		total_written_bytes += written_bytes;
		if (!specs->next)
			break ;
		else
			specs = specs->next;
	}
	return (total_written_bytes);
}

void	free_spec(void *vspec)
{
	t_spec	*spec;

	spec = (t_spec *) vspec;
	free(spec->str);
	free(spec);
}

void	free_specs(t_spec_list **specs)
{
	ft_lstclear((t_list **) specs, &free_spec);
}
/**
 * @brief will print any of the arguments in a format specified by the first
 * argument
 *
 * 1. get_specs_str_from_format_str: will split the format string into a list of
 *  specifications (each spec connected to one of the arguments or to a literal
 * that will be written out unmodified) and parse them to a t_spec type
 * structure
 * 2.
 *
 * @param format string with printf-like formatting
 * @param ... variable length list of variable type arguments to print
 * 			  (each argument must be addressed in the format string)
 * @return int will return the number of chars written to STDOUT
*/

int	ft_printf(const char *format, ...)
{
	t_spec_list	*specs;
	va_list		args;
	int			written_bytes;

	if (!*format)
		return (0);
	specs = NULL;
	if (!get_specs_str_from_format_str(format, &specs))
		return (-1);
	va_start(args, format);
	parse_specs(specs);
	written_bytes = write_output(specs, args);
	va_end(args);
	free_specs(&specs);
	return (written_bytes);
}
