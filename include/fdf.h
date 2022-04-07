/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:43:52 by kfum              #+#    #+#             */
/*   Updated: 2022/04/07 15:06:50 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1500
# define HEIGHT 1000
# define GL_SILENCE_DEPRECATION

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}				t_point;

typedef struct s_line
{
	int		dif1;
	int		dif2;
	int		sign_x;
	int		sign_y;
	int		dx;
	int		dy;
	int		color;
}				t_line;

typedef struct s_window
{
	void		*mlx;
	void		*window;
	void		*graphic;
	int			**matrix;
	int			x;
	int			y;	
	int			z;
	int			zoom;
	int			x_offset;
	int			y_offset;
	int			projection;
	int			color;
	t_point		point1;
	t_point		point2;
	t_point		**init;
	t_point		**pts;
	t_point		**transform;
	t_line		line;
}				t_window;

void	x_angle(float *y, float *z, float angle);
void	y_angle(float *x, float *z, float angle);
void	z_angle(float *x, float *y, float angle);
void	init_color(t_window *g_map, int x, int y, int color);
void	set_color1(t_window *g_map);
void	set_color2(t_window *g_map);
int		control(int key, t_window *g_map);
void	error_msg(char *msg);
void	init_graph(t_window *g_map);
int		all_in(t_window *g_map);
void	print_graph(t_window *g_map);
void	change_projection(t_window *g_map);
void	x_rotation(t_window *g_map, float angle);
void	y_rotation(t_window *g_map, float angle);
void	z_rotation(t_window *g_map, float angle);
int		**create_matrix(char **fdf, t_window *g_map);
void	create_window(t_window *g_map);
void	control_instruction1(t_window *g_map);
void	control_instruction2(t_window *g_map);

#endif
