/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:24:39 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 17:57:40 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_u_case(va_list arg)
{
	int				count;
	unsigned int	number_unsign;

	count = 0;
	number_unsign = va_arg(arg, unsigned int);
	count += ft_count(number_unsign);
	ft_putusign(number_unsign, 1);
	return (count);
}
