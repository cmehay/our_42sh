/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:36:17 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:42:54 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_del(void *content, size_t __attribute((unused)) content_size)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2_head;
	t_list	*lst2_prev;
	t_list	*lst2_current;

	lst2_head = ft_lstnew(lst->content, lst->content_size);
	if (lst2_head == NULL)
		return (NULL);
	lst2_head = f(lst2_head);
	lst2_prev = lst2_head;
	lst = lst->next;
	while (lst != NULL)
	{
		lst2_current = ft_lstnew(lst->content, lst->content_size);
		if (lst2_current == NULL)
		{
			ft_lstdel(&lst2_head, ft_del);
			return (NULL);
		}
		lst2_current = f(lst2_current);
		lst2_prev->next = lst2_current;
		lst = lst->next;
		lst2_prev = lst2_current;
	}
	return (lst2_head);
}
