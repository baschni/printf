/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_str.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:09:09 by baschnit          #+#    #+#             */
/*   Updated: 2024/11/07 02:07:42 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULL_STR_H
# define NULL_STR_H

# ifdef __linux__
#  define __ON_LINUX 1
# else
#  define __ON_LINUX 0
# endif

# define LINUX_OUTPUT_STR_NULL "(null)"
# define LINUX_OUTPUT_PTR_NULL "(nil)"

# define LEN_OSX_OUTPUT_STR_NULL 6
# define OSX_OUTPUT_STR_NULL "(null)"
# define OSX_OUTPUT_PTR_NULL "0x0"

#endif