/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:30:16 by lharvey           #+#    #+#             */
/*   Updated: 2020/01/06 11:14:07 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 < (unsigned char)*s2)
		return (-1);
	if ((unsigned char)*s1 == (unsigned char)*s2)
		return (0);
	else
		return (1);
}
