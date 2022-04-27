/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:59:43 by mliban-s          #+#    #+#             */
/*   Updated: 2022/03/28 15:36:10 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*second;

	second = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = second;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*second;

	second = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = second;
	write(1, "pb\n", 3);
}

void	ft_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*second;

	last = ft_lstlast(*stack_a);
	last->next = *stack_a;
	second = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = second;
	write(1, "ra\n", 3);
}

void	temp_ft_rotate_a(t_list **stack_a)
{
	t_list	*last;
	t_list	*second;

	last = ft_lstlast(*stack_a);
	last->next = *stack_a;
	second = (*stack_a)->next;
	(*stack_a)->next = NULL;
	*stack_a = second;
}

void	ft_rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*second;

	last = ft_lstlast(*stack_b);
	last->next = *stack_b;
	second = (*stack_b)->next;
	(*stack_b)->next = NULL;
	*stack_b = second;
	write(1, "rb\n", 3);
}
