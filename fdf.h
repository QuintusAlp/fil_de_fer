/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:06:33 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 16:09:30 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>   // Pour open
# include <unistd.h>  // Pour read et close
# include <stdio.h>   // Pour perror et printf

enum e_keys
{
	WIDTH = 1250,
	HIGH = 850,
	STENCE = 1,
};
// for image gestion mlx
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

// points xyz 
typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	double	p_x;
	double	p_y;
	int		color;
}	t_point;

//limit of the map 
typedef struct s_map_limit
{
	int	max_x;
	int	min_x;
	int	max_y;
	int	min_y;
	int	map_width;
	int	map_high;
}	t_map_limit;
//all data of the map
typedef struct s_map
{
	int			line_size;
	int			nbr_lines;
	long		size;
	t_point		*points;
	t_map_limit	limits;
}	t_map;
//drwline function
typedef struct s_drawline
{
	int		dx;
	int		dy;
	int		step;
	float	x;
	float	y;
	float	x_increment;
	float	y_increment;
}	t_drawline;

//vars 
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;
//--draw pixel--
void		ft_drawline(t_vars *data, t_point a, t_point b);
//--parsing--
t_map		ft_get_points(char *filename);
//--parsing utils--
int			ft_color(const char *str);
void		ft_count_size(int fd, t_map *map);
t_point		ft_newpoint(int x, int y, int z, int color);
//--center the map--
void		ft_centermap(t_map *map);
//--isometrique projection--
void		ft_isometrique(t_map *map);
//--link points--
void		ft_linkpoints(t_vars *data, t_map map);
//--projection--
void		ft_projections(t_map *map, void (*ft_projection)(t_map *));
//--errors--
void		ft_error(char *error_message);
//--translation--
void		ft_translation(t_vars *vars, int t_x, int t_y);

#endif