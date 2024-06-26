/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:40:00 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 13:02:48 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		free(vars->map.points);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 124)
		ft_translation(vars, 10, 0);
	if (keycode == 123)
		ft_translation(vars, -10, 0);
	if (keycode == 126)
		ft_translation(vars, 0, -10);
	if (keycode == 125)
		ft_translation(vars, 0, 10);
	return (0);
}

int	close_window(t_vars *vars)
{
	free(vars->map.points);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		ft_error("too many arguments");
	vars.map = ft_get_points(argv[1]);
	ft_projections(&vars.map, ft_isometrique);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HIGH, "fdf");
	vars.img = mlx_new_image(vars.mlx, WIDTH, HIGH);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel,
			&vars.line_length, &vars.endian);
	ft_linkpoints(&vars, vars.map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, ft_key, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
