/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:01:39 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/10 12:09:46 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	sizeneedle;

	i = 0;
	sizeneedle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i + sizeneedle <= len)
	{
		if (ft_strncmp(&(haystack[i]), needle, sizeneedle) == 0)
			return ((char *) haystack + i);
		i++;
	}
	return (0);
}
