/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:43:03 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/12 14:35:44 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newele;

	newele = (t_list *)malloc(sizeof(t_list));
	if (!newele)
		return (NULL);
	newele->content = content;
	newele->next = NULL;
	return (newele);
}
