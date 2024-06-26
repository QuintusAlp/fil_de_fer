/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:34:44 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 13:04:04 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_img_reset(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, WIDTH, HIGH);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

void	ft_translation(t_vars *vars, int t_x, int t_y)
{
	int	i;

	i = 0;
	ft_img_reset(vars);
	while (i < vars->map.size)
	{
		vars->map.points[i].p_x += t_x;
		vars->map.points[i].p_y += t_y;
		i++;
	}
	ft_linkpoints(vars, vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
