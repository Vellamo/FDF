/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:53:53 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/04 11:35:46 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	i = 0;
	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (!len || dst == src)
		return (dst);
	if (dst_cpy < src_cpy)
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	else
		while (++i <= len)
			dst_cpy[len - i] = src_cpy[len - i];
	return (dst);
}
