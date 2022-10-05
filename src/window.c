/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:12:33 by kfum              #+#    #+#             */
/*   Updated: 2022/04/06 14:12:33 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** Getting the number from file and insert to structure
*/
int	**get_value(char **graph, t_window *g_map)
{
	int		i;
	int		j;
	int		len;
	int		**array;
	char	**split;

	array = (int **)malloc(sizeof(int *) * g_map->x);
	i = 0;
	while (i < g_map->x)
	{
		j = -1;
		len = 0;
		split = ft_strsplit(graph[i], ' ');
		while (split[len])
			len++;
		array[i] = (int *)malloc(sizeof(int) * len);
		while (split[++j])
			array[i][j] = ft_atoi(split[j]);
		i++;
	}
	g_map->y = len;
	return (array);
}

/*
** Getting the X & Y and putting it to structure
*/
static void	create_points(t_window *g_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_map->x)
	{
		j = 0;
		while (j < g_map->y)
		{
			g_map->pts[i][j].x = ((j + 1) - g_map->y / 2);
			g_map->pts[i][j].y = ((i + 1) - g_map->x / 2);
			g_map->pts[i][j].z = g_map->matrix[i][j];
			g_map->init[i][j] = g_map->pts[i][j];
			j++;
		}
		i++;
	}
}

/*
** Putting all the input to struct then create a pop up window
*/
void	create_window(t_window *g_map)
{
	int	i;

	i = 0;
	init_graph(g_map);
	g_map->pts = (t_point **)malloc(sizeof(t_point) * g_map->x);
	g_map->transform = (t_point **)malloc(sizeof(t_point) * g_map->x);
	g_map->init = (t_point **)malloc(sizeof(t_point) * g_map->x);
	while (i < g_map->x)
	{
		g_map->pts[i] = (t_point *)malloc(sizeof(t_point) * g_map->y);
		g_map->transform[i] = (t_point *)malloc(sizeof(t_point) * g_map->y);
		g_map->init[i++] = (t_point *)malloc(sizeof(t_point) * g_map->y);
	}
	create_points(g_map);
	change_projection(g_map);
	g_map->mlx = mlx_init();
	g_map->window = mlx_new_window(g_map->mlx, WIDTH, HEIGHT, FDF);
	g_map->graphic = mlx_new_image(g_map->mlx, WIDTH, HEIGHT);
	mlx_hook(g_map->window, 2, 3, control, g_map);
	mlx_loop_hook(g_map->mlx, &all_in, g_map);
	mlx_loop(g_map->mlx);
}

/*
** Instruction for the controls that show on screen Part1
*/
void	control_instruction1(t_window *g_map)
{
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 190, 0x00FFFFFF,
		MOVE);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 180, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 170, 0x00FFFFFF,
		ZOOM);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 160, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 150, 0x00FFFFFF,
		COLOR);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 140, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 130, 0x00FFFFFF,
		DEFAULT);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 120, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 110, 0x00FFFFFF,
		PRO);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 100, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 90, 0x00FFFFFF,
		X_AXIS);
}

/*
** Instruction for the controls that show on screen Part2
*/
void	control_instruction2(t_window *g_map)
{
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 80, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 70, 0x00FFFFFF,
		Y_AXIS);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 60, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 50, 0x00FFFFFF,
		Z_AXIS);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 40, 0x00FFFFFF, "");
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 30, 0x00FFFFFF,
		ESC);
	mlx_string_put(g_map->mlx, g_map->window, 20, HEIGHT - 20, 0x00FFFFFF, "");
}
