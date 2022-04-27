/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliban-s <mliban-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:22:02 by mliban-s          #+#    #+#             */
/*   Updated: 2022/04/05 22:12:31 by mliban-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# include <stddef.h>
# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_screen
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_rev;
	void	*img_conso;
	void	*img_floor;
	void	*img_whole;
	void	*img_end;
	void	*img_end_open;
	int		orient;
	int		numbers_of_collec;
	char	**map;
	int		pos_conso_x;
	int		pos_conso_y;
	int		x;
	int		y;
	int		actif;
	int		count;
}				t_screen;

typedef struct s_dim
{
	int	heigth;
	int	width;
}				t_dim;

void	ft_my_map(t_screen *t_screen, char *argv);
int		ft_my_map2(t_screen *t_screen);
int		ft_move_pixels(int keycode, t_screen *t_screen);
void	ft_key_2(int keycode, t_screen *t_screen);
void	ft_key_13(int keycode, t_screen *t_screen);
void	ft_key_1(int keycode, t_screen *t_screen);
void	ft_key_0(int keycode, t_screen *t_screen);
int		ft_valid(int keycode, t_screen *t_screen);
int		ft_add_verf(t_screen *t_screen);
void	ft_my_verificat(t_screen *t_screen);
int		ft_clean_win(t_screen *t_screen);
t_dim	ft_heigth_width(t_screen *t_screen);
int		ft_top_x(t_screen *t_screen);
int		ft_left_y(t_screen *t_screen);
int		ft_right_y(t_screen *t_screen);
int		ft_bottom_x(t_screen *t_screen);
int		ft_mon_exit(void);
int		init_img(t_screen *display, int width, int height);
void	ft_parse_map2(t_screen *t_screen, int i, int j);
void	ft_parse_map(t_screen *t_screen, int i, int j, char *line);
void	ft_deal_with_c(t_screen *t_screen, int i, int j, char *line);
void	ft_deal_with_zero(t_screen *t_screen, int i, int j, char *line);
void	ft_deal_with_one(t_screen *t_screen, int i, int j, char *line);
void	ft_deal_with_p(t_screen *t_screen, int i, int j, char *line);
void	ft_deal_with_e(t_screen *t_screen, int i, int j, char *line);
void	ft_deal_with_c2(t_screen *t_screen, int i, int j);
void	ft_deal_with_zero2(t_screen *t_screen, int i, int j);
void	ft_deal_with_one2(t_screen *t_screen, int i, int j);
void	ft_deal_with_p2(t_screen *t_screen, int i, int j);
void	ft_deal_with_e2(t_screen *t_screen, int i, int j);
void	ft_protec(t_screen *t_screen, char *result);
void	display_count(t_screen *t_screen);
void	ft_wrong_map(int fd, char *result);
void	ft_check_file(char **argv);
int		ft_strlen1(char const *str);
void	*free_strings(char **strings, t_dim t_dim);
void	ft_protect_free(t_screen *t_screen, char *result);
#endif