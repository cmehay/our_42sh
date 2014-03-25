/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:07:55 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/06 11:20:36 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	long	size;
	size_t	i;
	char	*rtn;

	len = ft_strlen(s) - 1;
	if ((int)len == -1)
		return (ft_strnew(1));
	start = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	size = len - start;
	if ((rtn = (char*)ft_memalloc(sizeof(char) * (size * (size > 0) + 1))))
	{
		while (start < len + 1)
			rtn[i++] = s[start++];
	}
	return (rtn);
}

char	*cool_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	long	size;
	size_t	i;
	char	*rtn;

	len = ft_strlen(s) - 1;
	if ((int)len == -1)
		return (cool_strnew(1));
	start = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	size = len - start;
	if ((rtn = (char*)cool_malloc(sizeof(char) * (size * (size > 0) + 1))))
	{
		while (start < len + 1)
			rtn[i++] = s[start++];
	}
	return (rtn);
}

char	*ft_strtrim_cpy(char *s)
{
	char	*cpy;

	cpy = ft_strtrim(s);
	ft_strclr(s);
	ft_strcpy(s, cpy);
	free(cpy);
	return (s);
}
