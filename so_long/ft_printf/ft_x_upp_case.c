/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_upp_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:21:39 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:57:55 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_x_upp_case(va_list arg)
{
	int				count;
	unsigned int	hexa_number_upper;

	count = 0;
	hexa_number_upper = va_arg(arg, unsigned int);
	count += ft_count_hexa(hexa_number_upper);
	ft_hexa(hexa_number_upper, 1, ft_toupper);
	return (count);
}
