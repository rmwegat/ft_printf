/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:44:18 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/20 15:09:56 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	getptrlen(uintptr_t ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		i++;
		ptr = ptr / 16;
	}
	return (i);
}

void	printptr(uintptr_t ptr)
{
	char	c;

	if (ptr >= 16)
	{
		printptr(ptr / 16);
		printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			c = ptr + '0';
			write(1, &c, 1);
		}
		else
		{
			c = ptr - 10 + 'a';
			write(1, &c, 1);
		}
	}
}

int	ft_printptr(unsigned long ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (!ptr)
	{
		i++;
		write(1, "0", 1);
	}
	else
	{
		printptr(ptr);
		i += getptrlen(ptr);
	}
	return (i);
}
