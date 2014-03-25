/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:30:11 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/25 23:42:34 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void		*destroy_glob(t_glob *lst)
{
	if (lst)
	{
		destroy_glob(lst->next);
		cool_free(lst->file);
		cool_free(lst);
	}
	return (NULL);
}

static t_glob	*new_match(char *file, char *pattern)
{
	t_glob	*item;

	if (!matching(pattern, file) || (*pattern != '.' && *file == '.'))
		return (NULL);
	item = (t_glob*)cool_malloc(sizeof(t_glob));
	item->file = file;
	item->len = ft_strlen(item->file);
	return (item);
}

t_glob			*add_to_match(char *file, char *pattern, t_bool reset)
{
	static t_glob	*lst = NULL;
	t_glob			*tmp;

	tmp = lst;
	if (reset)
		lst = destroy_glob(lst);
	if (file)
	{
		if (!lst)
			lst = new_match(file, pattern);
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_match(file, pattern);
		}
	}
	return (lst);
}

static void		copy_in_str(t_glob *lst, char *cpy)
{
	while (lst)
	{
		ft_strcat(cpy, lst->file);
		ft_strcat(cpy, " ");
		lst = lst->next;
	}
}

char			*glob_to_str(t_glob *lst)
{
	char	*rtn;
	size_t	len;
	t_glob	*bak;

	len = 0;
	bak = lst;
	while (lst)
	{
		len += lst->len + 1;
		lst = lst->next;
	}
	if (!len)
		return (NULL);
	rtn = cool_strnew(len);
	copy_in_str(bak, rtn);
	return (rtn);
}
