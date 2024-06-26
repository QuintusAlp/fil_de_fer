/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qalpesse <qalpesse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:59:41 by qalpesse          #+#    #+#             */
/*   Updated: 2024/06/07 16:12:48 by qalpesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_positionstr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoibase(char *str, char *base)
{
	int	i;
	int	is_neg;
	int	res;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	i += 3;
	while (ft_strchr(base, str[i]) && str[i] != '\0')
	{
		res = (res * ft_strlen(base)) + (ft_positionstr(base, str[i++]));
	}
	return (res * is_neg);
}
// #include <stdio.h>
// int main(void)
// {
// 	char str[] = " fdfefe ";
// 	printf("%d\n", ft_atoibase(str, "0123456789abcdef"));
// 	return (0);
// }