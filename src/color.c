/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:37:39 by kfum              #+#    #+#             */
/*   Updated: 2022/04/07 16:13:12 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Get different colors (R,G,B)
*/
void	init_color(t_window *g_map, int x, int y, int color)
{
	char	*graph;
	int		g;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		graph = mlx_get_data_addr(g_map->graphic, &g, &g, &g);
		g = WIDTH * y * 4 + x * 4;
		graph[g + 0] = (int)((color >> 16) & 0xFF);
		graph[g + 1] = (int)((color >> 8) & 0xFF);
		graph[g + 2] = (int)((color) & 0xFF);
	}
}

/*
** Fill the X line color
*/
static void	fill_color1(t_window *g_map, int i, int j)
{
	if ((g_map->init[i][j].z < g_map->init[i][j + 1].z)
		|| (g_map->init[i][j].z > g_map->init[i][j + 1].z))
	{
		if (g_map->color == 0)
			g_map->line.color = 0x0646464;
		if (g_map->color == 1)
			g_map->line.color = 0x00000FF;
		if (g_map->color == 2)
			g_map->line.color = 0x000FF00;
		if (g_map->color == 3)
			g_map->line.color = 0x0FF0000;
	}
}

/*
** Fill the Y line color
*/
static void	fill_color2(t_window *g_map, int i, int j)
{
	if ((g_map->init[i][j].z < g_map->init[i + 1][j].z)
		|| (g_map->init[i][j].z > g_map->init[i + 1][j].z))
	{
		if (g_map->color == 0)
			g_map->line.color = 0x0646464;
		if (g_map->color == 1)
			g_map->line.color = 0x00000FF;
		if (g_map->color == 2)
			g_map->line.color = 0x000FF00;
		if (g_map->color == 3)
			g_map->line.color = 0x0FF0000;
	}
}

/*
** Fill the X line with color then print out
*/
void	set_color1(t_window *g_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_map->x)
	{
		j = 0;
		while (j < g_map->y - 1)
		{
			g_map->line.color = 0x00FFFFFF;
			fill_color1(g_map, i, j);
			g_map->point1 = g_map->transform[i][j++];
			g_map->point2 = g_map->transform[i][j];
			print_graph(g_map);
		}
	}
}

/*
** Fill the Y line with color then print out
*/
void	set_color2(t_window *g_map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < g_map->y)
	{
		i = 0;
		while (i < g_map->x - 1)
		{
			g_map->line.color = 0x00FFFFFF;
			fill_color2(g_map, i, j);
			g_map->point1 = g_map->transform[i++][j];
			g_map->point2 = g_map->transform[i][j];
			print_graph(g_map);
		}
	}
}
