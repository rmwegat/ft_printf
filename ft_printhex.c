/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:42:49 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/20 15:06:19 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	getnbrlen(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	printhex(unsigned int num, char c)
{
	if (num >= 16)
	{
		printhex(num / 16, c);
		printhex(num % 16, c);
	}
	else
	{
		if (num <= 9)
		{
			c = num + '0';
			write(1, &c, 1);
		}
		else
		{
			c = num - 10 + c;
			write(1, &c, 1);
		}
	}
}

int	ft_printhex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else if (format == 'x')
		printhex(num, 'a');
	else if (format == 'X')
		printhex(num, 'A');
	return (getnbrlen(num));
}
