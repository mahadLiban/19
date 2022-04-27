/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:57:35 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:50:15 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long n, int fd, int (*f)(int))
{
	if (n == 0)
		write(1, "0", fd);
	else
	{
		if (n >= 16)
		{
			ft_hexa(n / 16, fd, f);
			ft_hexa(n % 16, fd, f);
		}
		else
		{
			if (n < 10)
				ft_putchar_fd((n + '0'), 1);
			else
				ft_putchar_fd(f(n + 'A' - 10), fd);
		}
	}
}
