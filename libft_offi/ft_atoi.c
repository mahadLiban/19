/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:44:03 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/12 15:45:47 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	resultat;
	int			sign;

	sign = 1;
	resultat = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		resultat = resultat * 10 + *str++ - '0';
		if (resultat < 0)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
	}
	return (resultat * sign);
}
