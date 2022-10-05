/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:57:08 by kfum              #+#    #+#             */
/*   Updated: 2022/10/05 11:17:33 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Set the graphic back to the original position
*/
static void	back_to_default(t_window *g_map)
{
	int	i;
	int	j;

	i = 0;
	g_map->zoom = 30;
	g_map->z = 2;
	g_map->x_offset = WIDTH / 2;
	g_map->y_offset = HEIGHT / 2;
	while (i < g_map->x)
	{
		j = 0;
		while (j < g_map->y)
		{
			g_map->pts[i][j] = g_map->init[i][j];
			j++;
		}
		i++;
	}
}

/*
** Key input setting part1
*/
static void	key_setting1(int key, t_window *g_map)
{
	if (key == 53)
		error_msg(EXIT);
	if (key == 15)
		g_map->color = 1;
	if (key == 5)
		g_map->color = 2;
	if (key == 11)
		g_map->color = 3;
	if (key == 46)
		g_map->color = 0;
	if (key == 12)
		back_to_default(g_map);
	if (key == 24)
		g_map->zoom += 1;
	if (key == 27)
	{
		if (g_map->zoom != 1)
			g_map->zoom -= 1;
	}
	if (key == 0)
		g_map->x_offset -= 10;
	if (key == 2)
		g_map->x_offset += 10;
}

/*
** Key input setting part2
*/
static void	key_setting2(int key, t_window *g_map)
{
	if (key == 13)
		g_map->y_offset -= 10;
	if (key == 1)
		g_map->y_offset += 10;
	if (key == 6)
		g_map->projection = 0;
	if (key == 7)
		g_map->projection = 1;
	if (key == 8)
		g_map->projection = 2;
	if (key == 126)
		x_rotation(g_map, 0.099);
	if (key == 125)
		x_rotation(g_map, -0.099);
	if (key == 123)
		z_rotation(g_map, 0.099);
	if (key == 124)
		z_rotation(g_map, -0.099);
	if (key == 43)
		y_rotation(g_map, -0.099);
	if (key == 47)
		y_rotation(g_map, 0.099);
}

/*
** Putting all the key settings into 1 function
*/
int	control(int key, t_window *g_map)
{
	key_setting1(key, g_map);
	key_setting2(key, g_map);
	change_projection(g_map);
	return (0);
}
