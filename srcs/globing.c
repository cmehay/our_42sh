/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 20:47:26 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/06 11:17:30 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <dirent.h>

t_bool		matching(char *pattern, char *lookup)
{
	if (!*pattern && !*lookup)
		return (TRUE);
	if (*pattern == '*' && *(pattern + 1) && !*lookup)
		return (FALSE);
	if (*pattern == '?' || *pattern == *lookup)
		return matching(pattern + 1, lookup + 1);
	if (*pattern == '*')
		return (matching(pattern + 1, lookup) || matching(pattern, lookup + 1));
	return (FALSE);
}

static void	find_pattern_dir(int depth, char *dir, char *pattern)
{
	struct dirent	*file;
	DIR				*opdir;
	char			*cpy;

	depth--;
	if (!dir || !pattern || !(opdir = opendir(dir)))
		return ((void)cool_free(dir));
	while ((file = readdir(opdir)))
	{
		if (depth && ft_strcmp(file->d_name, ".")
			&& ft_strcmp(file->d_name, ".."))
			find_pattern_dir(depth, next_dir(dir, file->d_name), pattern);
		else if (!depth && ft_strcmp(file->d_name, ".")
			&& ft_strcmp(file->d_name, ".."))
		{
			cpy = next_dir(dir, file->d_name);
			cpy = (*cpy == '.' && *(cpy + 1) == '/')
				? ft_memmove(cpy, cpy + 2, ft_strlen(cpy) - 1)
				: ft_memmove(cpy, cpy + 1, ft_strlen(cpy));
			add_to_match(cpy, pattern, FALSE);
		}
	}
	closedir(opdir);
	cool_free(dir);
}

char		*looking_for_match(char *str)
{
	char	**split;
	char	*dir;
	int		depth;

	split = cool_strsplit(str, '/');
	dir = (*str == '/') ? "/" : ".";
	depth = 0;
	while (split && *split++)
		depth++;
	add_to_match(NULL, NULL, TRUE);
	find_pattern_dir(depth, dir, str);
	return (glob_to_str(add_to_match(NULL, NULL, FALSE)));
}

char		*globing(char *str)
{
	char	*cpy;
	char	*rep;
	char	**split;
	char	**array_cpy;
	char	*rtn;

	cpy = cool_strdup(str);
	split = cool_strsplit(sanityze(cpy = cool_strdup(str)), ' ');
	array_cpy = split;
	cool_free(cpy);
	while (split && *split && *(++split))
	{
		if (ft_strchr(*split, '*') || ft_strchr(*split, '?'))
		{
			if (!(rep = looking_for_match(*split)))
				ms_not_match(*split);
			cool_free(*split);
			*split = (rep) ? rep : cool_strnew(0);
		}
	}
	rtn = cool_strmerge(array_cpy, ' ');
	cool_arraydel(array_cpy);
	return (rtn);
}

char		*globing_test(char *str)
{
	char	*rtn;

	rtn = str;
	if (ft_strchr(str, '*') || ft_strchr(str, '?'))
	{
		rtn = globing(str);
		if (rtn && !ft_strchr(rtn, ' '))
		{
			cool_free(rtn);
			rtn = cool_strnew(0);
		}
	}
	return (rtn);
}
