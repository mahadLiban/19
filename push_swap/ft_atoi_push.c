/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:22:24 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/01 20:49:36 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_push(const char *str, int *numbers)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
		if (*str == '\0')
			ft_free_exit(numbers);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result < 0)
		{
			if (result == -2147483648 && *str == '\0' && sign == -1)
				return (-2147483648);
			ft_free_exit(numbers);
		}
	}
	if (*str && !(*str >= '0' && *str <= '9'))
		ft_free_exit(numbers);
	return (sign * result);
}

void	ft_free_exit(int *numbers)
{
	free(numbers);
	ft_exit("Error\n");
}

int	if_sort(t_list *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (*(int *)lst->content != i)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

void	ft_exit(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}		
	exit (1);
}
