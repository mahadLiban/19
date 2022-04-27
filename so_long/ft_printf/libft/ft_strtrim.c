/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:50 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/13 10:59:14 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	setting(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*word;
	int			start;
	int			end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && setting(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= 0 && setting(s1[end], set))
		end--;
	end += 1;
	if (start > end)
		return (ft_strdup(""));
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s1 + start, (end - start + 1));
	return (word);
}
