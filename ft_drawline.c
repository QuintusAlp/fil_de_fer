/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:28:38 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/12 12:11:46 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_drawline(t_vars *data, t_point a, t_point b)
{
	t_drawline	v;
	int			i;

	v.dx = b.p_x - a.p_x;
	v.dy = b.p_y - a.p_y;
	if (abs(v.dx) > abs(v.dy))
		v.step = abs(v.dx);
	else
		v.step = abs(v.dy);
	v.x_increment = v.dx / (float)v.step;
	v.y_increment = v.dy / (float)v.step;
	v.x = a.p_x;
	v.y = a.p_y;
	i = 0;
	while (i <= v.step)
	{
		if ((v.x > 0 && v.x < WIDTH) && (v.y > 0 && v.y < HIGH))
			my_mlx_pixel_put(data, v.x, v.y, a.color);
		v.x += v.x_increment;
		v.y += v.y_increment;
		i++;
	}
}

void	ft_linkpoints(t_vars *data, t_map map)
{
	int	i;
	int	k;
	int	tab_limit;

	i = 0;
	k = -1;
	tab_limit = map.line_size * map.nbr_lines;
	while (i < tab_limit - 1)
	{
		k++;
		if (k >= map.line_size - 1)
			k = -1;
		else
			ft_drawline(data, map.points[i], map.points[i + 1]);
		if (i + map.line_size < tab_limit)
			ft_drawline(data, map.points[i], map.points[i + map.line_size]);
		i++;
	}
}
