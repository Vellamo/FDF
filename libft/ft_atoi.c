/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:29:55 by lharvey           #+#    #+#             */
/*   Updated: 2020/02/27 09:20:10 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	unsigned int		result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (result * 10) + ((unsigned int)(str[i]) - '0');
		++i;
	}
	if (result > 2147483648)
		return ((sign == -1) ? 0 : -1);
	return (sign * result);
}
