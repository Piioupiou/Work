/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 04:13:18 by pgallois          #+#    #+#             */
/*   Updated: 2014/01/19 23:13:37 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WOLF3D_H
# define WOLF3D_H

# define PI180 0.01745329251
# define BLOCK 512
# include "../libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include <X.h>
# include <math.h>

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

typedef struct		s_player
{
	int				height;
	int				len_to_proj;
	int				x;
	int				y;
	int				move;
	int				turn;
	float			direction;
	int				fov;
	float			inertie;
}					t_player;

typedef struct		s_pproj
{
	int				x_max;
	int				y_max;
	int				x_center;
	int				y_center;
	double			ratio_ray;
}					t_pproj;

typedef struct		s_image
{
	char			*sky;
	char			*floor;
	char			*cockpit;
	int				width[4];
	int				width2;
	int				width_floor;
	int				width_sky;
	int				height[4];
	int				height2;
	int				height_floor;
	int				height_sky;
	char			*textur[4];
	char			*image;
	int				Ax_h;
	int				Ay_v;
	int				i;
	int				bits_text[4];
	int				bits_cockpit;
	char			*adr_textur[4];
	char			*adr_cockpit;
	char			*adr_sky;
	char			*adr_floor;
	int				endian;
	int				endian_floor;
	int				endian_sky;
	int				endian_cockpit;
	int				endian_text[4];
	char			*data;
	int				sizeline;
	int				sizeline_sky;
	int				sizeline_floor;
	int				sizeline_text[4];
	int				sizeline_cockpit;
	int				bits;
	int				bits_floor;
	int				bits_sky;
}					t_image;

typedef struct		s_struct
{
	int				*data;
	int				size_X;
	int				size_Y;
	t_pproj			*pproj;
	t_image			*image;
	t_player		*player;
	void			*mlx;
	void			*win;
	int				i;
}					t_struct;

						/* Fonction in main.c : */

void				ft_putpix_image(t_image *img, int x, int y, unsigned long color);
int					ft_expose(t_struct **matr);
int					ft_key(t_struct **matr);
void				ft_mlx(int fd);

						/* Fonction in ft_raycasting.c : */

void				ft_raycasting(t_player *player, t_pproj *proj, t_struct **matr, t_image *image);
double				*ft_raycasting2(double *alpha, t_player *player);
int					ft_rotate_text(t_struct **matr, double alpha);

						/* Fonction in ft_colision.c : */

t_struct			**ft_colision_up(t_struct **matr, int i);
t_struct			**ft_colision_up2(int *x, int *y, t_struct **matr, int i);
t_struct			**ft_colision_down(t_struct **matr, int i);
t_struct			**ft_colision_down2(int *x, int *y, t_struct **matr, int i);

						/* Fonction in ft_init.c : */

t_struct			**ft_creatematr(t_struct **matr, int fd);
t_image				*ft_init_image(t_image *img, void *mlx);
void				clear(t_image *image, t_struct **matr);
t_pproj				*ft_init_pproj(t_pproj *proj);
t_player			*ft_init_player(t_player *player, t_pproj *proj);

						/* Fonction in ft_draw.c : */

t_image				*ft_draw_colone(t_struct **matr, double lenght1, double alpha, int i);
double				ft_check_vertical(t_player *player, t_struct **matr, double alpha);
double				ft_check_vertical2(t_struct **matr, t_player *player, int *X, int *Y);
double				ft_check_horizontal(t_player *player, t_struct **matr, double alpha);
double				ft_check_horizontal2(t_struct **matr, t_player *player, int *X, int *Y);

						/* Fonction in ft_tools.c : */

int					ft_relaise(int key, t_struct **matr);
int					ft_mask(int key, t_struct **matr);
void				ft_freeall(t_struct **matr);
void				ft_go(t_struct **matr);
t_struct			*ft_get_number(char **str);

#endif /* WOLF3D_H */
