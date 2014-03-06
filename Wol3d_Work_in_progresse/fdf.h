/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 11:36:49 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/04 02:57:44 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define CTE1 0.8
# define CTE2 0.9
# define X 30
# define Y 40
# define Z -0.055

#include "libft/libft.h"
#include <fcntl.h>
#include <mlx.h>

typedef struct		s_iso
{
	double			x;
	double			y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	unsigned long	color;
}					t_iso;

typedef struct		s_image
{
	char			*image;
	int				endian;
	char			*data;
	int				sizeline;
	int				bits;
}					t_image;

typedef struct		s_struct
{
	int				*data;
	int				size;
	void			*mlx;
	void			*win;
}					t_struct;

void				ft_mlx(int fd);
t_struct			*ft_get_number(char **str);
int					send_key(int key);
int					ft_expose(t_struct **matr);
t_struct			**ft_creatematr(int fd);
t_struct			*ft_get_number(char **str);
void				ft_putpix(t_struct **matr);
int					ft_dispmatr(t_struct **matr);
t_struct			**ft_creatematr(int fd);
void				ft_draw_y(t_image *img, int i, int j, t_struct **matr);
void				ft_draw_x(t_image *img, int i, int j, t_struct **matr);

#endif /* FDF_H */
