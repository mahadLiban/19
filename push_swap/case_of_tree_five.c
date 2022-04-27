/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_tree_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:22:17 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/01 20:47:14 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_of_two(t_list **stack_a)
{
	t_list	*stack;
	int		a;
	int		b;

	stack = *stack_a;
	a = (*(int *) stack->content);
	b = (*(int *) stack->next->content);
	if (a > b)
		ft_swap_a(stack_a);
}

void	ft_case_of_tree(t_list **stack_a)
{
	int		a;
	int		b;
	int		c;

	a = (*(int *)(*stack_a)->content);
	b = (*(int *)(*stack_a)->next->content);
	c = (*(int *)(*stack_a)->next->next->content);
	if (a < b && b < c)
		return ;
	if (a > b && a < c)
		ft_swap_a(stack_a);
	else if (a > b && b > c)
	{
		ft_swap_a(stack_a);
		ft_reverse_retate_a(stack_a);
	}
	else if (a > b && b < c)
		ft_rotate_a(stack_a);
	else if (a < b && a < c)
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
	}
	else if (a < b && b > c)
		ft_reverse_retate_a(stack_a);
}

void	ft_case_of_five(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	t_list	*ptr;

	i = 0;
	while (i++ < 2)
	{
		ptr = *stack_a;
		j = 0;
		while (ptr && (*(int *) ptr->content) >= 3 && j++ >= 0)
			ptr = ptr->next;
		if (j <= 3)
			while (j-- > 0)
				ft_rotate_a(stack_a);
		else
			while (j++ < 5)
				ft_reverse_retate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
	if ((*(int *)(*stack_b)->content) < (*(int *)(*stack_b)->next->content))
		ft_swap_b(stack_b);
	ft_case_of_tree(stack_a);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
}

void	ft_case_of_four(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	t_list	*ptr;

	i = 0;
	j = 0;
	while (i++ < 1)
	{
		ptr = *stack_a;
		j = 0;
		while (ptr && (*(int *) ptr->content) >= 2 && j++ >= 0)
			ptr = ptr->next;
		if (j <= 3)
			while (j-- > 0)
				ft_rotate_a(stack_a);
		else
			while (j++ < 4)
				ft_reverse_retate_a(stack_a);
		ft_push_b(stack_a, stack_b);
	}
	ft_case_of_tree(stack_a);
	ft_push_a(stack_a, stack_b);
}
