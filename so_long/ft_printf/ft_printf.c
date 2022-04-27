/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:03:17 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 18:09:32 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_count_hexa(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{		
		if (format[i] == '%')
		{
			i++;
			count += ft_form(format, arg, i);
		}
		else
		{
			count += 1 ;
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
