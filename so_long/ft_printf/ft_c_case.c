/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:34:50 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:47:50 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c_case(va_list arg)
{
	int	count;

	count = 0;
	count += 1;
	ft_putchar_fd(va_arg(arg, int), 1);
	return (count);
}
