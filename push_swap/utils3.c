/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:57:40 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/01 19:54:28 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_dupli(int *number, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc -1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (number[i] == number[j])
				ft_exit("Error\n");
			j++;
		}
		i++;
	}
}

int	*ft_parse(int argc, char **argv)
{
	int	i;
	int	*numbers;

	i = 1;
	if (argc < 2)
		exit(1);
	numbers = malloc(sizeof(int) * (argc - 1));
	if (!numbers)
	{
		free(numbers);
		return (NULL);
	}
	while (argc > i)
	{
		numbers[i - 1] = ft_atoi_push(argv[i], numbers);
		i++;
	}
	return (numbers);
}
