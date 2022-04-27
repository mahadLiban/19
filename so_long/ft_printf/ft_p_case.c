/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:55:38 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:51:04 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_p_case(va_list arg)
{
	int				count;
	unsigned long	pointer;

	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	pointer = va_arg(arg, unsigned long);
	count += ft_count_hexa(pointer);
	ft_hexa(pointer, 1, ft_tolower);
	return (count);
}
