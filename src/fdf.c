/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfum <kfum@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:05 by kfum              #+#    #+#             */
/*   Updated: 2022/10/05 11:19:13 by kfum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
**	Print out messages
*/
void	error_msg(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_window	g_map;
	char		*file;
	char		**graph;
	int			fd;

	if (argc != 2)
		error_msg(ERR_PARM);
	graph = (char **)malloc(sizeof(char *) * 1000);
	ft_bzero(graph, 1000);
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd == -1)
		error_msg(ERR_FILE);
	g_map.x = 0;
	while (get_next_line(fd, &file) > 0)
	{
		graph[g_map.x] = ft_strdup(file);
		g_map.x++;
	}
	graph[g_map.x] = 0;
	g_map.matrix = get_value(graph, &g_map);
	create_window(&g_map);
	close(fd);
	return (0);
}
