/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 00:19:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/01 19:44:07 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static char	*sanityze(char *str)
{
	char	*rtn;

	rtn = str;
	while (str && *str)
	{
		*str = (*str == '\t') ? ' ' ? *str;
		str++;
	}
	return (rtn);
}

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

static char	*find_pattern_dir(char **split, )
{

}

char		*looking_for_match(char *str)
{
	char	**split;
	char	**bak;
	char	*dir;
	char	*tmp;
	char	*pattern;

	split = cool_strsplit(str, '/');
	bak = split;
	while (split && *split)
	{
		if (!*(split + 1))
		{
			pattern = cool_strdup(*split);
			*split = NULL;
		}
		split++;
	}
	tmp = cool_strmerge(bak);
	if (*str == '/')
		dir = (tmp) ? cool_strjoin("/", tmp) : cool_strdup("/");
	else
		dir = (tmp) ? cool_strjoin("./", tmp) : cool_strdup("./");
	cool_free(tmp);
	cool_arraydel(bak);
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
	rtn = cool_strmerge(array_cpy);
	cool_arraydel(array_cpy);
	return (rtn);
}
