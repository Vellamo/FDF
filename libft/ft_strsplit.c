/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:27:03 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/05 17:10:25 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	wordcnt(char const *s, char c)
{
	int a;
	int wordcount;

	a = 0;
	wordcount = 0;
	while (s[a] != '\0')
	{
		while (s[a] == c)
			a++;
		if ((s[a] != c) && (s[(a + 1)] == c))
		{
			wordcount++;
		}
		a++;
	}
	return (wordcount);
}

static int	cnt(char const *s, char c)
{
	int		b;

	b = 0;
	while ((s[b] != '\0') && (s[b] != c))
		b++;
	return (b);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**fresh;

	i = 0;
	if (!s || !c)
		return (0);
	if (!(fresh = (char **)malloc((wordcnt(s, c) + 2) * (sizeof(char *)))))
		return (0);
	while (*s != '\0')
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(fresh[i] = ft_strnew(cnt(&s[j], c) + 1)))
				fresh[i] = 0;
			while ((*s != c) && (*s != '\0'))
				fresh[i][j++] = (char)*s++;
			fresh[i++][j] = '\0';
		}
	}
	fresh[i] = 0;
	return (fresh);
}
