/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:25:44 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/11 12:02:12 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtn;
	size_t	i;

	i = 0;
	if ((rtn = ft_strnew(ft_strlen(s))) != NULL)
	{
		while (s[i] != 0)
		{
			rtn[i] = f(s[i]);
			i++;
		}
	}
	return (rtn);
}

char	*cool_strmap(char const *s, char (*f)(char))
{
	char	*rtn;
	size_t	i;

	i = 0;
	if ((rtn = cool_strnew(ft_strlen(s))) != NULL)
	{
		while (s[i] != 0)
		{
			rtn[i] = f(s[i]);
			i++;
		}
	}
	return (rtn);
}
