/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:57:49 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/07 14:06:36 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_itoa(int n)
{
	char			*fresh;
	int				len;
	int				negative;
	unsigned int	num;

	len = ft_intlen(n);
	negative = (n < 0) ? 1 : 0;
	num = (n < 0) ? -n : n;
	if (!(fresh = (char *)malloc(((len) + 1) * (sizeof(char)))))
		return (0);
	fresh[len--] = '\0';
	while (len >= 0)
	{
		fresh[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (negative == 1)
		fresh[0] = '-';
	return (fresh);
}
