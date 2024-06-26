/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:21:46 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 13:11:51 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_stence(t_map *map)
{
	int	stence;

	stence = 0;
	while ((map->limits.map_high - 1) * stence < HIGH * 3 / 4
		&& (map->limits.map_width - 1) * stence < WIDTH * 1 / 2)
		stence++;
	return (stence);
}

void	ft_isometrique(t_map *map)
{
	int		i;
	int		stence;

	stence = ft_stence(map);
	i = 0;
	while (i < map->size)
	{
		map->points[i].p_x *= stence;
		map->points[i].p_y *= stence;
		i++;
	}
	map->limits.map_width = (map->limits.map_width - 1) * stence;
	map->limits.map_high = (map->limits.map_high - 1) * stence;
	map->limits.max_x = (map->limits.max_x - 1) * stence;
	map->limits.min_x = (map->limits.min_x - 1) * stence;
	map->limits.max_y = (map->limits.max_y - 1) * stence;
	map->limits.min_y = (map->limits.min_y - 1) * stence;
	return ;
}

void	ft_projections(t_map *map, void (*ft_projection)(t_map *))
{
	ft_projection(map);
	ft_centermap(map);
}
