/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:33:20 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/29 14:17:41 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long d)
{
	int	len;

	len = 0;
	if (d < 0)
	{
		len += ft_putchar('-');
		len += ft_putnbr(-d);
	}
	else if (d > 9)
	{
		len += ft_putnbr(d / 10);
		len += ft_putnbr(d % 10);
	}
	else
		len += ft_putchar(d + 48);
	return (len);
}

int	ft_hexadecimal(unsigned long a, char *s)
{
	int	len;

	len = 0;
	if (a > 15)
		len += ft_hexadecimal(a / 16, s);
	len += ft_putchar(s[a % 16]);
	return (len);
}
