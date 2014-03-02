/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:30:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/02 17:15:58 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void		*destroy_glob(t_glob *lst)
{
	if (lst)
	{
		destroy_glob(lst->next);
		cool_free(lst->file);
		cool_free(lst->path);
		cool_free(lst->path - 2);
		cool_free(lst);
	}
	return (NULL);
}

t_glob		*new_match(char *file, char *path)
{
	t_glob	*item;
	int		i;

	i = -1;
	item = (t_glob*)cool_malloc(sizeof(t_glob));
	item->file = file;
	while (path[++i])
		;
	item->path = (path[i - 1] == '/') ? path : cool_strjoin(path, "/");
	if (*(item->path) == '.' && *(item->path + 1) == '/')
		item->path += 2;
	item->len = ft_strlen(item->file) + ft_strlen(item->path);
	return (item);
}

t_glob		*add_to_match(char *file, char *path, t_bool reset)
{
	static t_glob	*lst = NULL;
	t_glob			*tmp;

	tmp = lst;
	if (reset)
		lst = destroy_glob(lst);
	if (file)
	{
		if (!lst)
			lst = new_match(file, path);
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_match(file, path);
		}
	}
	return (lst);
}

static void	copy_in_str(t_glob *lst, char *cpy)
{
	while (lst)
	{
		if (lst->match)
		{
			ft_strcat(cpy, lst->path);
			ft_strcat(cpy, lst->file);
			ft_strcat(cpy, " ");
		}
		lst = lst->next;
	}
}

char		*glob_to_str(t_glob *lst)
{
	char	*rtn;
	size_t	len;
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
	copy_in_str(bak, rtn);
	return (rtn);
}

