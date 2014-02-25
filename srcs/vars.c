/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 20:35:52 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/25 01:39:33 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "stdlib.h"

t_vars	*gimme_vars(void)
{
	static t_vars	*lst = NULL;

	if (!lst)
		lst = (t_vars*)cool_malloc(sizeof(t_vars));
	return (lst);
}

t_vars	*new_var(char *name, char *content)
{
	t_vars	*rtn;

	rtn = (t_vars*)cool_malloc(sizeof(t_vars));
	rtn->content = cool_strdup(content);
	rtn->name = cool_strdup(name);
	return (rtn);
}

void	rm_local_var(char *name)
{
	t_vars	*lst;
	t_vars	*to_free;

	lst = gimme_vars;
	while (lst->next)
	{
		if (lst->next->name && ft_strequ(name, lst->next->name))
		{
			cool_free(lst->next->content);
			cool_free(lst->next->name);
			to_free = lst->next;
			lst->next = lst->next->next;
			cool_free(to_free);
			return ;
		}
		lst = lst->next;
	}
}

void	add_local_var(char *name, char *content)
{
	t_vars	*lst;

	lst = gimme_vars;
	while (lst)
	{
		if (lst->name && ft_strequ(name, lst->name))
		{
			cool_free(lst->content);
			lst->content = cool_strdup(content);
			return ;
		}
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	lst->next = new_var(name, content);
}

char	*find_local_var(char *name)
{
	t_vars	*lst;

	lst = gimme_vars;
	while (lst)
	{
		if (lst->name && ft_strequ(name, lst->name))
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
