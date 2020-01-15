/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:53:55 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/05 12:03:50 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;
	int				strlen;

	i = 0;
	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (!(fresh = (char *)malloc(1 + strlen * (sizeof(*s)))))
		return (0);
	while (*s != '\0')
	{
		fresh[i] = (char)(*f)(i, *s);
		s++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
