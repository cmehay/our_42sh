/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 11:23:20 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/26 00:01:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_alloc_lst	*gimme_ptr_lst(void)
{
	static t_alloc_lst	*lst = NULL;

	if (!lst)
	{
		lst = (t_alloc_lst*)malloc(sizeof(t_alloc_lst));
		lst->ptr = -1;
		lst->next = NULL;
	}
	return (lst);
}

void				add_to_lst(void *ptr)
{
	t_alloc_lst	*new_item;
	t_alloc_lst	*current_lst;

	new_item = (t_alloc_lst*)malloc(sizeof(t_alloc_lst));
	new_item->ptr = (ssize_t)ptr;
	new_item->next = NULL;
	current_lst = gimme_ptr_lst();
	while (current_lst->next)
		current_lst = current_lst->next;
	current_lst->next = new_item;
}

void				*cool_malloc(size_t len)
{
	void	*alloc;

	if (!(alloc = ft_memalloc(len)))
		return (alloc);
	add_to_lst(alloc);
	return (alloc);
}

void				cool_free(void *ptr)
{
	t_alloc_lst	*lst;
	t_alloc_lst	*prev;

	lst = gimme_ptr_lst();
	prev = lst;
	while (lst->next)
	{
		if (lst->ptr == (ssize_t)ptr)
		{
			free(ptr);
			prev->next = lst->next;
			free(lst);
			return ;
		}
		prev = lst;
		lst = lst->next;
	}
	if (lst->ptr == (ssize_t)ptr)
	{
		free(ptr);
		prev->next = NULL;
		free(lst);
	}
}
