/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:03:01 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/05 11:59:35 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;
	int		strlen;

	i = 0;
	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (!(fresh = (char *)malloc(1 + strlen * (sizeof(*s)))))
		return (0);
	while (*s != '\0')
	{
		fresh[i] = (char)(*f)(*s);
		s++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
