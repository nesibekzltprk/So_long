/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:33:15 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/29 14:17:37 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_check(char c, va_list arg);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(long d);
int		ft_hexadecimal(unsigned long a, char *s);
void	ft_begin(const char *s, va_list arg, int *check);

#endif
