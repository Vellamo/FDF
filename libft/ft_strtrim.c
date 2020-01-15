/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:59:05 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/08 11:30:15 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*fresh;

	i = 0;
	if (!s)
		return (0);
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (fresh = ft_strnew(0));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	fresh = ft_strsub(s, i, (j - i) + 1);
	return (fresh);
}
