/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_str.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:10:03 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:07:00 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FORMAT_STR_H
# define PARSE_FORMAT_STR_H

# include "t_spec.h"

t_spec	*newspec(char *s, char conv);
void	parse_spec(void *spec);

#endif