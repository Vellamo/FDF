/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lharvey <lharvey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:14:26 by lharvey           #+#    #+#             */
/*   Updated: 2019/11/07 13:45:15 by lharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*ptr;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	temp = (*f)(lst);
	if (!(newlist = ft_lstnew(temp->content, temp->content_size)))
		return (0);
	ptr = newlist;
	lst = lst->next;
	while (lst)
	{
		temp = (*f)(lst);
		if (!(newlist->next = ft_lstnew(temp->content, temp->content_size)))
			return (0);
		newlist = newlist->next;
		lst = lst->next;
	}
	return (ptr);
}
