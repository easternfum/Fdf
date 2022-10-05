/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:45:40 by kfum              #+#    #+#             */
/*   Updated: 2022/04/07 16:13:16 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Rounded up the number
*/
static int	rounded_up(float number)
{
	int		i;
	float	j;
	int		flag;

	flag = 1;
	if (number < 0)
	{
		number *= -1;
		flag = -1;
	}
	i = number;
	j = number - (int)number;
	if (j < 0.5)
	{
		return ((int)(i * flag));
	}		
	return ((int)((i + 1) * flag));
}

/*
** Calculation for the isometric projection
*/
static t_point	i_projection(t_point p, t_window *g_map)
{
	t_point	new_point;
	float	x;
	float	y;

	x = g_map->zoom * p.x * 0.866 + g_map->zoom * (p.y * 0.866);
	x = rounded_up(x);
	new_point.x = x + g_map->x_offset;
	y = g_map->z * p.z + g_map->zoom * (p.x * 0.5) - g_map->zoom * (p.y * 0.5);
	y = rounded_up(y);
	new_point.y = g_map->y_offset - y;
	return (new_point);
}

/*
** Calculation for the cabinet projection
*/
static t_point	c_projection(t_point p, t_window *g_map)
{
	t_point	new_point;
	float	x;
	float	y;

	x = g_map->zoom * p.x * 0.707 + g_map->zoom * (p.y);
	x = rounded_up(x);
	new_point.x = x + g_map->x_offset;
	y = g_map->z * p.z + g_map->zoom * (p.x * 0.707);
	y = rounded_up(y);
	new_point.y = g_map->y_offset - y;
	return (new_point);
}

/*
** Calculation for the plan projection
*/
static t_point	p_projection(t_point p, t_window *g_map)
{
	t_point	new_point;
	float	x;
	float	y;

	x = g_map->zoom * p.x * 0.707 + g_map->zoom * (p.y * 0.707);
	x = rounded_up(x);
	new_point.x = x + g_map->x_offset;
	y = g_map->z * p.z + g_map->zoom * (p.x * 0.707)
		- g_map->zoom * (p.y * 0.707);
	y = rounded_up(y);
	new_point.y = g_map->y_offset - y;
	return (new_point);
}

/*
** Function that allow to change projection
*/
void	change_projection(t_window *g_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_map->x)
	{
		j = 0;
		while (j < g_map->y)
		{
			if (g_map->projection == 0)
			{
				g_map->transform[i][j] = i_projection(g_map->pts[i][j], g_map);
			}
			if (g_map->projection == 1)
			{
				g_map->transform[i][j] = c_projection(g_map->pts[i][j], g_map);
			}				
			if (g_map->projection == 2)
			{
				g_map->transform[i][j] = p_projection(g_map->pts[i][j], g_map);
			}				
			j++;
		}
		i++;
	}
}
