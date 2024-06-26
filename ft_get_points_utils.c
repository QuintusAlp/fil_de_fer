/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_points_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:24:27 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 15:57:04 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_newpoint(int x, int y, int z, int color)
{
	t_point	point;
	double	a;

	point.color = color;
	point.x = x;
	point.y = y;
	point.z = z;
	a = 26.57 * (M_PI / 180);
	point.p_x = x * cos(a) + y * cos(a + 2) + z * cos(a - 2);
	point.p_y = x * sin(a) + y * sin(a + 2) + z * sin(a - 2);
	return (point);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

void	ft_count_size(int fd, t_map *map)
{
	int		j;
	char	*gnl;

	gnl = NULL;
	while (1)
	{
		j = 0;
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		map->nbr_lines++;
		j = ft_count(gnl, ' ');
		map->line_size = j;
		map->size += j;
		free(gnl);
	}
}

int	ft_color(const char *str)
{
	if (ft_strrchr(str, ','))
		return (ft_atoibase(ft_strrchr(str, ','), "0123456789abcdef"));
	else
		return (0xfdfefe);
}
