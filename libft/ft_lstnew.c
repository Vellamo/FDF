/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:15:14 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/07 10:15:20 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(*lstnew))))
		return (0);
	if (!content)
	{
		lstnew->content = 0;
		lstnew->content_size = 0;
	}
	else
	{
		lstnew->content = (void *)malloc(content_size);
		if (!(lstnew->content))
		{
			free(lstnew);
			return (0);
		}
		ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
	}
	lstnew->next = 0;
	return (lstnew);
}
