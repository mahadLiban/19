/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:10:11 by mliban-s          #+#    #+#             */
/*   Updated: 2022/02/01 11:10:04 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	s = malloc(sizeof(char) * (ft_strlen(memoir) - i + 1));
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
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*str;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	str = ft_buf(fd, buffer[fd]);
	if (!str)
		return (NULL);
	line = ft_line(str);
	buffer[fd] = ft_memoir(str);
	return (line);
}
