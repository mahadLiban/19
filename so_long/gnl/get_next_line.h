/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:35:55 by prince            #+#    #+#             */
/*   Updated: 2022/03/10 20:02:08 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlen2(char *str);
char			*ft_strchr2(char *s, int c);
char			*ft_strjoin2(char *s1, char *s2);
char			*get_next_line(int fd);
char			*ft_line(char *memoir);
char			*ft_memoir(char *memoir);
char			*ft_buf(int fd, char *str);

#endif