/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:05:55 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/12 14:40:58 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_ele;
	t_list	*ptr;

	ptr = *alst;
	if (!ptr)
	{
		*alst = new;
		return ;
	}
	last_ele = ft_lstlast(ptr);
	last_ele->next = new;
}
