/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:59:08 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/04 12:05:34 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*number;
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	ft_check_args(argc, argv);
	number = ft_parse(argc, argv);
	while (i < argc - 1)
		ft_lstadd_back(&stack_a, ft_lstnew(&number[i++]));
	the_index(stack_a, number, argc);
	if (if_sort(stack_a))
	{
		free(number);
		ft_lstclear(&stack_a, NULL);
		exit (0);
	}
	sort_numbers(argc, &stack_a, &stack_b);
	free (number);
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
}

void	sort_numbers(int argc, t_list **stack_a, t_list **stack_b)
{
	if (argc - 1 == 2)
		ft_case_of_two(stack_a);
	if (argc - 1 == 3)
		ft_case_of_tree(stack_a);
	if (argc - 1 == 4)
		ft_case_of_four(stack_a, stack_b);
	if (argc - 1 == 5)
		ft_case_of_five(stack_a, stack_b);
	if (argc - 1 > 5)
		ft_case_of_all(stack_a, stack_b);
}
