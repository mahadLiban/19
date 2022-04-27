/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:50:34 by prince            #+#    #+#             */
/*   Updated: 2022/03/10 20:02:30 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *memoir)
{
	int		i;
	char	*s;

	i = 0;
	if (!memoir[i])
		return (NULL);
	while (memoir[i] && memoir[i] != '\n' )
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (memoir[i] && memoir[i] != '\n')
	{
		s[i] = memoir[i];
		i++;
	}
	if (memoir[i] == '\n')
	{
		s[i] = memoir[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_memoir(char *memoir)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (memoir[i] && memoir[i] != '\n')
		i++;
	if (!memoir[i])
	{
		free(memoir);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen2(memoir) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (memoir[i])
		s[c++] = memoir[i++];
	s[c] = '\0';
	free(memoir);
	return (s);
}

char	*ft_buf(int fd, char *str)
{
	char	*buf;
	int		bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr2(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin2(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memoir;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memoir = ft_buf(fd, memoir);
	if (!memoir)
		return (NULL);
	line = ft_line(memoir);
	memoir = ft_memoir(memoir);
	return (line);
}
