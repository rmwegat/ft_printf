/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:51:22 by rwegat            #+#    #+#             */
/*   Updated: 2023/11/17 15:22:59 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include "./libft/libft.h"

int	ft_printchar(int c);
int	ft_printf(const char *format, ...);
int	ft_printhex(unsigned int num, const char format);
int	ft_printint(int num);
int	ft_printpercent(void);
int	ft_printptr(unsigned long ptr);
int	ft_printstr(char *string);
int	ft_printunsigned(unsigned int num);

#endif