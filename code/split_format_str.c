/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_format_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:37 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 03:12:22 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"
#include "parse_format_str.h"
#include "free_spec.h"

#define ALLOWED_DELIMITERS "cspdiuxX%"

t_spec	*newspec(char *s, char conv)
{
	t_spec	*spec;

	spec = malloc(sizeof (t_spec));
	if (!spec)
		return (NULL);
	spec->str = s;
	spec->conv = conv;
	return (spec);
}

static char	*ptr_substr(const char *start, const char *end)
{
	char	*result;
	char	*temp;
	size_t	len;

	len = end - start + 2;
	if (len <= 0)
		len = 1;
	result = malloc(len);
	if (!result)
		return (NULL);
	temp = result;
	while (start <= end)
	{
		*result = *start;
		start++;
		result++;
	}
	*result = '\0';
	return (temp);
}

int	add_new_spec_list_item(const char *start, \
const char *end, char conv, t_spec_list **specs)
{
	t_spec		*spec;
	t_spec_list	*item;
	char		*p_substr;

	p_substr = ptr_substr(start, end);
	if (!p_substr)
		return (0);
	spec = newspec(p_substr, conv);
	if (!spec)
		return (free(p_substr), 0);
	item = (t_spec_list *) ft_lstnew(spec);
	if (!item)
		return (free_spec(spec), 0);
	ft_lstadd_back((t_list **) specs, (void *) item);
	return (1);
}

/**
 * @brief add new spec if applicable
 *
 * spcstr will be called on every char in the original format str. When the
 * first percentage is found it will be marked as the start of a new
 * specification. If a start is already present, than the string will be scanned
 *  for the next allowed delimiter to end the current specification. and add it
 * to the back of the list. The lit pointer points to the first character after
 * the last spec. If this is not a percentage (the start of a new spec), then a
 * literal string will be created until the next percentage or the end of the
 * format string.
 *
*/
static int	spcstr(const char *frm, const char **st, \
const char **lit, t_spec_list **specs)
{
	if (!*st)
	{
		if (*frm == '%')
		{
			*st = frm;
			if (*lit != frm)
			{
				if (!add_new_spec_list_item(*lit, frm - 1, 'l', specs))
					return (0);
				*lit = NULL;
			}
		}
		return (1);
	}
	if (ft_strchr(ALLOWED_DELIMITERS, *frm))
	{
		if (!add_new_spec_list_item(*st + 1, frm, '-', specs))
			return (0);
		*st = NULL;
		*lit = frm + 1;
	}
	return (1);
}

int	get_specs_str_from_format_str(const char *format, t_spec_list **specs)
{
	const char	*spec_started;
	const char	*literal;

	spec_started = NULL;
	literal = format;
	while (*format)
	{
		if (!spcstr(format, &spec_started, &literal, specs))
			return (free_specs(specs), 0);
		format++;
	}
	if (literal && *literal)
		if (!add_new_spec_list_item(literal, format - 1, 'l', specs))
			return (free_specs(specs), 0);
	if (spec_started)
		return (free_specs(specs), 0);
	return (1);
}
