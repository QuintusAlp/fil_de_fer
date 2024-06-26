/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_centermap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:04:59 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/01 15:55:27 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_centermap(t_map *map)
{
	int	i;
	int	dx;
	int	dy;

	dx = (WIDTH - map->limits.max_x) - ((WIDTH - map->limits.map_width) / 2);
	dy = (HIGH - map->limits.max_y) - ((HIGH - map->limits.map_high) / 2);
	i = 0;
	while (i < map->size)
	{
		map->points[i].p_x += dx;
		map->points[i].p_y += dy;
		i++;
	}
	return ;
}
