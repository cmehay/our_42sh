/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 16:13:09 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/02 21:26:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*sanityze(char *str)
{
	char	*rtn;

	rtn = str;
	while (str && *str)
	{
		*str = (*str == '\t') ? ' ' : *str;
		str++;
	}
	return (rtn);
}

char	*next_dir(char *dir, char *file)
{
	char	*rtn;

	rtn = cool_strnew(ft_strlen(dir) + ft_strlen(file) + 1);
	ft_strcat(rtn, dir);
	ft_strcat(rtn, "/");
	ft_strcat(rtn, file);
	return (rtn);
}
