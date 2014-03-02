/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:30:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/02 01:43:16 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	*destroy_glob(t_glob *lst)
{
	if (lst)
	{
		destroy_glob(lst->next);
		cool_free(lst->file);
		cool_free(item->path);
		cool_free(lst);
	}
	return (NULL);
}

t_glob	new_match(char *file, char *path)
{
	t_glob	*item;
	int		i;

	i = -1;
	item = (t_glob*)cool_malloc(sizeof(t_glob));
	item->file = file;
	while (path[++i])
		;
	item->path = (path[i - 1] == '/') ? path : cool_strjoin(path, "/");
	item->len = ft_strlen(item->file) + ft_strlen(item->path) + 1;
	return (item);
}

t_glob	add_to_match(char *file, char *path, t_bool reset)
{
	static t_glob	*lst = NULL;
	t_glob			*tmp;

	tmp = lst;
	if (reset)
		lst = destroy_glob(lst);
	if (str)
	{
		if (!lst)
			lst = new_match(str);
		else
		{
			while (tmp->next)
				tmp = tmp->next
			tmp->next = new_match(str);
		}
	}
	return (lst);
}



char	*glob_to_str(t_glob *lst, )
{
	char	*rtn;
	char	*cpy;
	size_t	*len;
	t_glob	*bak;

	len = 0;
	bak = lst;
	while (lst)
	{
		if (lst->match)
			len += lst->len + 1;
		lst = lst->next;
	}
	rtn = cool_strnew(len);
	cpy = rtn;
	while (bak)
	{
		if (lst->match)
		{
			ft_strcpy(cpy, lst->file);
			cpy = cpy + lst->len;
			*cpy++ = ' ';
		}
	}
}

