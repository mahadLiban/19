/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:44:33 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/18 18:10:41 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_case(va_list arg)
{
	int		count;
	char	*string;

	count = 0;
	string = va_arg(arg, char *);
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	else
	{
		count += ft_strlen(string);
		ft_putstr_fd(string, 1);
	}
	return (count);
}
