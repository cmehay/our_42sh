/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 00:41:40 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/21 10:24:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*new_str(char *s1, int s2_len, char *str)
{
	int		s1_len;
	int		str_len;
	int		i;
	char	*str_srch;

	i = 0;
	str_srch = str;
	s1_len = ft_strlen(s1);
	str_len = ft_strlen(str);
	while (*str_srch && (str_srch = ft_strstr(str_srch, s1)))
	{
		i++;
		str_srch += s1_len;
	}
	return (ft_strnew(str_len + ((s2_len - s1_len) * i)));
}

static char		*cool_new_str(char *s1, int s2_len, char *str)
{
	int		s1_len;
	int		str_len;
	int		i;
	char	*str_srch;

	i = 0;
	str_srch = str;
	s1_len = ft_strlen(s1);
	str_len = ft_strlen(str);
	while (*str_srch && (str_srch = ft_strstr(str_srch, s1)))
	{
		i++;
		str_srch += s1_len;
	}
	return (cool_strnew(str_len + ((s2_len - s1_len) * i)));
}

char			*ft_strrep(char *s1, char *s2, char *str)
{
	char	*rtn;
	char	*str_srch;
	int		i;
	int		shift1;
	int		shift2;

	shift1 = ft_strlen(s1);
	shift2 = ft_strlen(s2);
	if (!(rtn = new_str(s1, ft_strlen(s2), str)))
		return (NULL);
	ft_strcpy(rtn, str);
	i = 0;
	str_srch = str;
	while (*str_srch && (str_srch = ft_strstr(str_srch, s1)))
	{
		if (!str_srch)
			str_srch = str + ft_strlen(str);
		ft_strcpy(rtn + (str_srch - str) + ((shift2 - shift1) * i), s2);
		str_srch += shift1;
		i++;
		ft_strcpy(rtn + (str_srch - str) + ((shift2 - shift1) * i), str_srch);
	}
	return (rtn);
}

char			*cool_strrep(char *s1, char *s2, char *str)
{
	char	*rtn;
	char	*str_srch;
	int		i;
	int		shift1;
	int		shift2;

	shift1 = ft_strlen(s1);
	shift2 = ft_strlen(s2);
	if (!(rtn = cool_new_str(s1, ft_strlen(s2), str)))
		return (NULL);
	ft_strcpy(rtn, str);
	i = 0;
	str_srch = str;
	while (*str_srch && (str_srch = ft_strstr(str_srch, s1)))
	{
		if (!str_srch)
			str_srch = str + ft_strlen(str);
		ft_strcpy(rtn + (str_srch - str) + ((shift2 - shift1) * i), s2);
		str_srch += shift1;
		i++;
		ft_strcpy(rtn + (str_srch - str) + ((shift2 - shift1) * i), str_srch);
	}
	return (rtn);
}
