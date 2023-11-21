/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:59:40 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/17 15:10:35 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (string[i])
	{
		write (1, &string[i], 1);
		i++;
	}
	return (i);
}
