/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 00:19:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/01 00:33:46 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_bool	matching(char *pattern, char *lookup)
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

