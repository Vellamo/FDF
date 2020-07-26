/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:55:57 by lharvey           #+#    #+#             */
/*   Updated: 2019/10/28 12:17:09 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char*)s;
	while (i < n)
	{
		if ((string)[i] == (unsigned char)c)
			return ((void *)string + i);
		i++;
	}
	return (0);
}
