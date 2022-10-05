/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:44:27 by kfum              #+#    #+#             */
/*   Updated: 2022/04/07 16:13:17 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Getting the X rotation
*/
void	x_rotation(t_window *g_map, float angle)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_map->x)
	{
		j = 0;
		while (j < g_map->y)
		{
			x_angle(&(g_map->pts[i][j].y), &(g_map->pts[i][j].z), angle);
			j++;
		}
		i++;
	}
}

/*
** Getting the Y rotation
*/
void	y_rotation(t_window *g_map, float angle)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_map->x)
	{
		j = 0;
		while (j < g_map->y)
		{
			y_angle(&(g_map->pts[i][j].x), &(g_map->pts[i][j].z), angle);
			j++;
		}
		i++;
	}
}

/*
** Getting the Z rotation
*/
void	z_rotation(t_window *g_map, float angle)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_map->x)
	{
		j = 0;
		while (j < g_map->y)
		{
			z_angle(&(g_map->pts[i][j].x), &(g_map->pts[i][j].y), angle);
			j++;
		}
		i++;
	}
}
