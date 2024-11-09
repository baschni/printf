/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:10:31 by baschnit          #+#    #+#             */
/*   Updated: 2024/09/21 13:10:31 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_digits(int n)
{
	int	digits;

	digits = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*target;
	char	*start;
	int		sign;

	digits = get_digits(n);
	sign = 1 - 2 * (n < 0);
	target = malloc(sizeof(char) * (digits + (n < 0) + 1));
	if (!target)
		return (NULL);
	start = target;
	if (n < 0)
		*(target++) = '-';
	target += digits;
	*target = '\0';
	target--;
	*target = sign * (n % 10) + '0';
	while (n / 10 != 0)
	{
		n = n / 10;
		target--;
		*target = sign * (n % 10) + '0';
	}
	return (start);
}
