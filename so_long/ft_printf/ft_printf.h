/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:08:29 by mliban-s          #+#    #+#             */
/*   Updated: 2022/01/19 12:14:13 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "stdarg.h"

unsigned int	ft_u_case(va_list arg);
unsigned long	ft_p_case(va_list arg);
unsigned int	ft_x_case(va_list arg);
unsigned int	ft_x_upp_case(va_list arg);
int				ft_printf(const char *format, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_count(long nb);
size_t			ft_strlen(char const *str);
int				ft_tolower(int c);
void			ft_hexa(unsigned long n, int fd, int (*f)(int));
int				ft_count_hexa(unsigned long nb);
int				ft_toupper( int c);
void			ft_putusign(unsigned int n, int fd);
int				ft_c_case(va_list arg);
int				ft_di_case(va_list arg);
int				ft_s_case(va_list arg);
int				ft_prct_case(void);
int				ft_form(const char *format, va_list arg, int i);

#endif