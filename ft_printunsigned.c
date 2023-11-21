/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:59:16 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/17 15:10:38 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int num)
{
	unsigned int	i;
	char			n;

	i = 0;
	if (num < 10)
	{
		n = num + '0';
		write(1, &n, 1);
		i++;
		return (i);
	}
	i += ft_printunsigned(num / 10);
	n = '0' + num % 10;
	write(1, &n, 1);
	i++;
	return (i);
}
