/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:27:56 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/11 12:00:45 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*rtn;
	t_strlen	s_len;
	size_t		i;
	size_t		j;

	s_len.s1 = ft_strlen(s1);
	s_len.s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if ((rtn = ft_strnew(s_len.s1 + s_len.s2)) == NULL)
		return (rtn);
	while (j < (s_len.s1 + s_len.s2))
	{
		if (s1[i] == 0)
		{
			rtn[j] = s2[j - s_len.s1];
			j++;
		}
		else
		{
			rtn[i] = s1[i];
			j = ++i;
		}
	}
	return (rtn);
}

char	*cool_strjoin(char const *s1, char const *s2)
{
	char		*rtn;
	t_strlen	s_len;
	size_t		i;
	size_t		j;

	s_len.s1 = ft_strlen(s1);
	s_len.s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if ((rtn = cool_strnew(s_len.s1 + s_len.s2)) == NULL)
		return (rtn);
	while (j < (s_len.s1 + s_len.s2))
	{
		if (s1[i] == 0)
		{
			rtn[j] = s2[j - s_len.s1];
			j++;
		}
		else
		{
			rtn[i] = s1[i];
			j = ++i;
		}
	}
	return (rtn);
}
