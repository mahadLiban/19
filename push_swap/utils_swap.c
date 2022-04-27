/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:26:03 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/01 20:44:45 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_index(t_list *stack_a, int *number, int argc)
{
	int		i;
	int		j;
	int		*data;
	int		count;
	t_list	*copy_stack_a;

	copy_stack_a = stack_a;
	i = 0;
	data = malloc(sizeof(int) * argc);
	if (!data)
		ft_exit("Error\n");
	while (stack_a)
	{
		j = 0;
		count = 1;
		while (j < argc - 1)
		{
			if (j != i && number[j] < number[i])
				count++;
			j++;
		}
		data[i++] = count;
		stack_a = stack_a->next;
	}
	ft_copy_stack(copy_stack_a, data);
}

void	ft_copy_stack(t_list *stack_a,	int	*data)
{
	t_list	*copy_stack_a;
	int		i;

	copy_stack_a = stack_a;
	i = 0;
	while (copy_stack_a)
	{
		(*(int *) copy_stack_a->content) = data[i];
		copy_stack_a = copy_stack_a->next;
		i++;
	}
	free(data);
}

void	ft_swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	first = *stack_a;
	second = (*stack_a)->next;
	(*stack_a)->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	first = *stack_b;
	second = (*stack_b)->next;
	(*stack_b)->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ft_swap_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	write(1, "ss\n", 3);
}
