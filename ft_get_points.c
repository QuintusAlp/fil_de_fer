/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:32:01 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 15:56:44 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_map_limits(t_map *map, int i)
{
	if (i == 0)
	{
		map->limits.max_x = map->points[i].p_x;
		map->limits.min_x = map->points[i].p_x;
		map->limits.max_y = map->points[i].p_y;
		map->limits.min_y = map->points[i].p_y;
	}
	else
	{
		if (map->points[i].p_x > map->limits.max_x)
			map->limits.max_x = map->points[i].p_x;
		if (map->points[i].p_y > map->limits.max_y)
			map->limits.max_y = map->points[i].p_y;
		if (map->points[i].p_x < map->limits.min_x)
			map->limits.min_x = map->points[i].p_x;
		if (map->points[i].p_y < map->limits.min_y)
			map->limits.min_y = map->points[i].p_y;
	}
	map->limits.map_width = abs(map->limits.max_x - map->limits.min_x);
	map->limits.map_high = abs(map->limits.max_y - map->limits.min_y);
}

static void	ft_splfree(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

void	ft_fill_points_tab(t_map *map, int fd)
{
	int		i;
	int		j;
	int		k;
	char	**spl;
	char	*gnl;

	i = -1;
	k = 0;
	while (i++, 1)
	{
		j = -1;
		gnl = get_next_line(fd);
		spl = ft_split(gnl, ' ');
		if (!spl)
			break ;
		while (j++, spl[j])
		{
			map->points[k + j] = ft_newpoint(j, i,
					ft_atoi(spl[j]), ft_color(spl[j]));
			ft_map_limits(map, k + j);
		}
		k += j;
		free(gnl);
		ft_splfree(spl);
	}
}

t_map	ft_initialize_map(void)
{
	t_map	map;

	map.line_size = 0;
	map.nbr_lines = 0;
	map.size = 0;
	map.points = NULL;
	return (map);
}

t_map	ft_get_points(char *filename)
{
	int		fd;
	int		fd2;
	t_map	map;

	map = ft_initialize_map();
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("file error");
	ft_count_size(fd, &map);
	map.points = malloc(map.size * sizeof(t_point));
	if (!map.points)
		ft_error("malloc error");
	fd2 = open(filename, O_RDONLY);
	if (fd2 == -1)
		ft_error("file error");
	ft_fill_points_tab(&map, fd2);
	close(fd);
	close(fd2);
	return (map);
}
