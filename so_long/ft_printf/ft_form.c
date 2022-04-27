/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:36:08 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:49:26 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_form(const char *format, va_list arg, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'c')
		count += ft_c_case(arg);
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_di_case(arg);
	else if (format[i] == 'p')
		count += ft_p_case(arg);
	else if (format[i] == 's')
		count += ft_s_case(arg);
	else if (format[i] == 'x')
		count += ft_x_case(arg);
	else if (format[i] == 'X')
		count += ft_x_upp_case(arg);
	else if (format[i] == 'u')
		count += ft_u_case(arg);
	else if (format[i] == '%')
		count += ft_prct_case();
	return (count);
}
