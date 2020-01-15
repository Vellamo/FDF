/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:46:58 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/19 15:13:37 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*fresh;
	unsigned int	strlens;

	if (!s1 || !s2)
		return (0);
	strlens = (ft_strlen(s1)) + (ft_strlen(s2));
	if (!(fresh = (char *)malloc((strlens + 1) * (sizeof(char *)))))
		return (0);
	ft_strcpy(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
