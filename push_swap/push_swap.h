/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:09:30 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/01 21:00:09 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
//# include "wraloc.h"

void	ft_swap_a(t_list **stack_a);
void	ft_swap_b(t_list **stack_b);
void	ft_swap_ss(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_a, t_list **stack_b);
void	ft_push_b(t_list **stack_a, t_list **stack_b);
void	ft_rotate_a(t_list **stack_a);
void	ft_rotate_b(t_list **stack_b);
t_list	*ft_one_before_last(t_list *stack_a);
void	ft_reverse_retate_a(t_list **stack_a);
void	ft_reverse_retate_b(t_list **stack_b);
void	ft_reverse_retate_r(t_list **stack_a, t_list **stack_b);
int		*ft_parse(int argc, char **argv);
int		ft_atoi_push(const char *str, int *numbers);
void	the_index(t_list *stack_a, int *number, int argc);
void	ft_case_of_tree(t_list **stack_a);
void	ft_case_of_five(t_list **stack_a, t_list **stack_b);
void	ft_case_of_two(t_list **stack_a);
void	ft_case_of_four(t_list **stack_a, t_list **stack_b);
void	ft_case_of_all(t_list **stack_a, t_list **stack_b);
int		if_sort(t_list *lst);
void	ft_check_args(int argc, char **argv);
void	ft_free_exit(int *numbers);
void	ft_copy_stack(t_list *stack_a,	int	*data);
void	sort_numbers(int argc, t_list **stack_a, t_list **stack_b);
void	ft_exit(char *str);
#endif
