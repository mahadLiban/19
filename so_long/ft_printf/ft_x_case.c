/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:17:50 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:57:11 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned	int	ft_x_case(va_list arg)
{
	int				count;
	unsigned int	hexa_number;

	count = 0;
	hexa_number = va_arg(arg, unsigned int);
	count += ft_count_hexa(hexa_number);
	ft_hexa(hexa_number, 1, ft_tolower);
	return (count);
}
