/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 09:41:31 by pgallois          #+#    #+#             */
/*   Updated: 2014/02/16 08:10:32 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/libft.h"
# include <mlx.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct		s_cam
{
	t_point			*pos;
	t_point			*direction;
	int				fov;
	double			dist_vue;
	double			long_vue;
	double			larg_vue;
	t_point			*HGvue;
	t_point			*H;
	t_point			*V;
	t_point			*U;
	t_point			*D;
}					t_cam;

typedef struct		s_image
{
	int				width;
	int				height;
	int				bits;
	int				endian;
	int				sizeline;
	char			*data;
	char			*image;
}					t_image;

typedef struct		s_sphere
{
	t_point			*o;
	double			r;
	unsigned long	color;
}					t_sphere;

typedef struct		s_lum
{
	t_point			*L;
	t_point			*o;
	unsigned long	color;
}					t_lum;

typedef struct		s_struct
{
	t_lum			*lum;
	t_cam			*cam;
	t_sphere		*sphere;
	t_image			*image;
	t_point			*D;
	t_point			*constV1;
	t_point			*constV2;
	t_point			*constV3;
	int				map[3];
	void			*mlx;
	void			*win;
}					t_struct;

int				send_key(int key);
void			free_all(t_struct *e);
double			ft_lenvect(t_point *p1);
t_struct		*ft_init_cam(t_struct *e, char **tmp);
t_struct		*ft_init_cam2(t_struct *e);
t_struct		*ft_init_sphere(t_struct *e, char **tmp);
t_point 		*ft_normevect(t_point *p);
t_point			*ft_prodscal_point(t_point *p1, t_point *p2);
double			ft_scalaire(t_point *p1, t_point *p2);
void			ft_putpix_image(t_image *img, int x, int y,
					unsigned long color);
t_point			*ft_factor_d_point(t_point *p, double i);
t_point			*ft_add_d_point(t_point *p, double i);
t_point			*ft_soustract_d_point(t_point *p, double i);
t_point			*ft_factor_point(t_point *p1, t_point *p2);
t_point			*ft_add_point(t_point *p1, t_point *p2);
t_point			*ft_expose_point(t_point *p1, t_point *p2);
t_point			*ft_soustract_point(t_point *p1, t_point *p2);
t_struct		*ft_init(int fd, t_struct *e);
unsigned long	ft_check_sphere(t_struct *e);
int				ft_raytracing(t_struct *e);
int				ft_mlx(int fd);

#endif /* RTV1_h */
