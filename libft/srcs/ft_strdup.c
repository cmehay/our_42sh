/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:41:48 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/11 11:59:11 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*rtn;

	i = 0;
	while (s1[i] != 0)
		i++;
	if ((rtn = ft_strnew(i)) != NULL)
	{
		rtn[i] = 0;
		while (i-- > 0)
			rtn[i] = s1[i];
	}
	return (rtn);
}

char	*cool_strdup(const char *s1)
{
	size_t	i;
	char	*rtn;

	i = 0;
	while (s1[i] != 0)
		i++;
	if ((rtn = cool_strnew(i)) != NULL)
	{
		rtn[i] = 0;
		while (i-- > 0)
			rtn[i] = s1[i];
	}
	return (rtn);
}
