/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 00:19:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/02 17:06:03 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <dirent.h>

t_bool		matching(char *pattern, char *lookup)
{
	if (!*pattern && !*lookup)
		return (_TRUE);
	if (*pattern == '*' && *(pattern + 1) && !*lookup)
		return (_FALSE);
	if (*pattern == '?' || *pattern == *lookup)
		return matching(pattern + 1, lookup + 1);
	if (*pattern == '*')
		return (matching(pattern + 1, lookup) || matching(pattern, lookup + 1));
	return (_FALSE);
}

static char	*find_pattern_dir(char **split, char *str)
{
	char	*dir;
	char	*tmp;

	tmp = cool_strmerge(split, '/');
	if (*str == '/')
		dir = (tmp) ? cool_strjoin("/", tmp) : cool_strdup("/");
	else
		dir = (tmp) ? cool_strjoin("./", tmp) : cool_strdup("./");
	cool_free(tmp);
	cool_arraydel(split);
	return (dir);
}

char		*find_match(char *dir, char *pattern)
{
	struct dirent	*file;
	DIR				*opdir;
	t_glob			*lst;

	add_to_match(NULL, NULL, _TRUE);
	if (!dir || !pattern || !(opdir = opendir(dir)))
		return (NULL);
	while ((file = readdir(opdir)))
	{
		if (*file->d_name != '.' || *pattern == '.')
		add_to_match(cool_strdup(file->d_name), dir, _FALSE);
	}
	lst = add_to_match(NULL, NULL, _FALSE);
	while (lst)
	{
		lst->match = matching(pattern, lst->file);
		lst = lst->next;
	}
	return (glob_to_str(add_to_match(NULL, NULL, _FALSE)));
}

char		*looking_for_match(char *str)
{
	char	**split;
	char	**bak;
	char	*dir;
	char	*pattern;

	split = cool_strsplit(str, '/');
	bak = split;
	pattern = NULL;
	while (split && *split)
	{
		if (!*(split + 1))
		{
			pattern = cool_strdup(*split);
			*split = NULL;
		}
		split++;
	}
	dir = find_pattern_dir(bak, str);
	return (find_match(dir, pattern));
}

char		*globing(char *str)
{
	char	*cpy;
	char	*rep;
	char	**split;
	char	**array_cpy;
	char	*rtn;

	cpy = cool_strdup(str);
	split = cool_strsplit(sanityze(cpy), ' ');
	array_cpy = split;
	cool_free(cpy);
	while (split && *split && *(++split))
	{
		if ((rep = looking_for_match(*split)))
		{
			cool_free(*split);
			*split = rep;
		}
	}
	rtn = cool_strmerge(array_cpy, ' ');
	ft_putendl(rtn);
	cool_arraydel(array_cpy);
	return (rtn);
}
