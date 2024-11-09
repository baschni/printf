/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:59:40 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:29:04 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "t_spec.h"
#include "libft.h"

void	parse_spec(void *vspec)
{
	t_spec	*spec;

	spec = (t_spec *) vspec;
	if (spec->conv != 'l')
		spec->conv = *(spec->str + ft_strlen(spec->str) - 1);
}
