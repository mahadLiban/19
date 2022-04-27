/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:53:07 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/08 16:27:33 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mot;
	size_t			i;

	i = 0;
	mot = (unsigned char *)s;
	while (i < n)
	{
		if (mot[i] == (unsigned char)c)
		{
			return ((void *) &mot[i]);
		}
		i++;
	}
	return (0);
}
