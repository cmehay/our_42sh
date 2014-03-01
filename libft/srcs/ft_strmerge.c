/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 16:42:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/01 16:59:22 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmerge(char **array, int c)
{
	int		len;
	char	**bak;
	char	*tmp;
	char	*cpy;
	char	*rtn;

	bak = array;
	len = 0;
	while (array && *array)
		len += ft_strlen(*array++) + 1;
	rtn = ft_strnew(len);
	cpy = rtn;
	while (bak && *bak)
	{
		tmp = *bak++;
		while (tmp && *tmp)
			*cpy++ = *tmp++;
		if (*(bak + 1))
			*cpy++ = (char)c;
	}
	return (rtn);
}

char	*cool_strmerge(char **array, int c)
{
	int		len;
	char	**bak;
	char	*tmp;
	char	*cpy;
	char	*rtn;

	bak = array;
	len = 0;
	while (array && *array)
		len += ft_strlen(*array++) + 1;
	rtn = cool_strnew(len);
	cpy = rtn;
	while (bak && *bak)
	{
		tmp = *bak++;
		while (tmp && *tmp)
			*cpy++ = *tmp++;
		if (*(bak + 1))
			*cpy++ = (char)c;
	}
	return (rtn);
}
