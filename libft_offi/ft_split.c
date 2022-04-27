/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:17:12 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/13 12:00:10 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_strings(char **strings, int current)
{
	int	i;

	i = 0;
	while (i < current)
	{
		free(strings[i]);
		i++;
	}
	free (strings);
	return (NULL);
}

static size_t	compeur(char const *s, char c)
{
	int	count;
	int	i;
	int	trigger;

	count = 0;
	trigger = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && trigger)
		{
			count++;
			trigger = 0;
		}
		if (s[i] == c && !trigger)
			trigger = 1;
		i++;
	}
	return (count);
}

static size_t	lenwords(char const *word, char c)
{
	size_t	i;

	i = 0;
	while (word[i] && word[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char		**word;
	size_t		iwords;
	int			i;

	if (!s)
		return (NULL);
	iwords = 0;
	i = 0;
	word = malloc(sizeof(char *) * (compeur(s, c) + 1));
	if (!word)
		return (0);
	word[compeur(s, c)] = NULL;
	while (iwords < compeur(s, c))
	{
		while (s[i] == c)
			i++;
		word[iwords] = malloc(sizeof(char) * (lenwords(s + i, c) + 1));
		if (!word[iwords])
			return (free_strings(word, iwords));
		ft_strlcpy(word[iwords], s + i, lenwords(s + i, c) + 1);
		i = i + lenwords(s + i, c);
		iwords++;
	}
	return (word);
}
