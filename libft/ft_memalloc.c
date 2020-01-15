/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:08:58 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/06 10:01:37 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	*temp;
	size_t			i;

	i = 0;
	if (!(temp = (void *)malloc(size)))
		return (0);
	ft_bzero(temp, size);
	return (temp);
}
