/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 00:19:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/01 16:33:59 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static char	*sanityze(char *str)
{
	char	*rtn;

	rtn = str;
	while (str && *str)
	{
		*str = (*str == '\t' || *str == '\n' ) ? ' ' ? *str;
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

char		*globing(char *str)
{
	char	*cpy;
	char	**split;

	cpy = cool_strdup(str);
	split = cool_strsplit(cpy, ' ');
	cool_free(cpy);
	while (split && *split && *(++split))
	{
		if ()
	}
}
