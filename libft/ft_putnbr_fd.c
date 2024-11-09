/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:24:21 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 19:24:21 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10 * (1 - 2 * (n < 0)), fd);
	c = '0' + (n % 10) * (1 - 2 * (n < 0));
	write(fd, &c, 1);
}
