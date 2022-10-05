/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:18:26 by kfum              #+#    #+#             */
/*   Updated: 2022/04/07 16:13:15 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Initialize the graphic output
*/
void	init_graph(t_window *g_map)
{
	g_map->zoom = 30;
	g_map->z = 2;
	g_map->x_offset = WIDTH / 2;
	g_map->y_offset = HEIGHT / 2;
	g_map->projection = 0;
	g_map->color = 0;
}

/*
** Part of printing out graphic function
*/
static t_window	*check_value(t_window *g_map)
{
	g_map->line.dx = fabs(g_map->point2.x - g_map->point1.x);
	g_map->line.dy = fabs(g_map->point2.y - g_map->point1.y);
	if (g_map->point1.x < g_map->point2.x)
		g_map->line.sign_x = 1;
	else
		g_map->line.sign_x = -1;
	if (g_map->point1.y < g_map->point2.y)
		g_map->line.sign_y = 1;
	else
		g_map->line.sign_y = -1;
	g_map->line.dif1 = g_map->line.dx - g_map->line.dy;
	return (g_map);
}

/*
**	Print out the graphic
*/
void	print_graph(t_window *g_map)
{
	check_value(g_map);
	while (g_map->point1.x != g_map->point2.x
		|| g_map->point1.y != g_map->point2.y)
	{
		init_color(g_map, g_map->point1.x, g_map->point1.y, g_map->line.color);
		g_map->line.dif2 = g_map->line.dif1 * 2;
		if (g_map->line.dif2 > -(g_map->line.dy))
		{
			g_map->line.dif1 -= g_map->line.dy;
			g_map->point1.x += g_map->line.sign_x;
		}
		if (g_map->line.dif2 < g_map->line.dx)
		{
			g_map->line.dif1 += g_map->line.dx;
			g_map->point1.y += g_map->line.sign_y;
		}
	}
}

/*
** Clear the graphic from structure
*/
static void	clean_graph(t_window *g_map)
{
	char	*graph;
	int		g;

	graph = mlx_get_data_addr(g_map->graphic, &g, &g, &g);
	ft_bzero(graph, 4 * WIDTH * HEIGHT);
}

/*
** Put all the print out functions into 1
*/
int	all_in(t_window *g_map)
{
	clean_graph(g_map);
	set_color1(g_map);
	set_color2(g_map);
	mlx_put_image_to_window(g_map->mlx, g_map->window, g_map->graphic, 0, 0);
	control_instruction1(g_map);
	control_instruction2(g_map);
	return (0);
}
