/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:17:54 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/20 17:04:25 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printformats(va_list args, const char format)
{
	int	charsprinted;

	charsprinted = 0;
	if (format == 'c')
		charsprinted += ft_printchar(va_arg(args, int));
	else if (format == 's')
		charsprinted += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		charsprinted += ft_printptr(va_arg(args, unsigned long));
	else if (format == 'i' || format == 'd')
		charsprinted += ft_printint(va_arg(args, int));
	else if (format == 'u')
		charsprinted += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		charsprinted += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		charsprinted += ft_printpercent();
	else
		return (-1);
	return (charsprinted);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		charsprinted;
	int		result;

	i = 0;
	charsprinted = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result = printformats(args, format[i + 1]);
			if (result == -1)
				return (va_end(args), -1);
			charsprinted += result;
			i++;
		}
		else
			charsprinted += write(1, &format[i], 1);
		i++;
	}
	return (va_end(args), charsprinted);
}
