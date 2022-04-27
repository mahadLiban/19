/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:40:25 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:48:23 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di_case(va_list arg)
{
	int	count;
	int	number;

	count = 0;
	number = va_arg(arg, int);
	count += ft_count(number);
	ft_putnbr_fd(number, 1);
	return (count);
}
