/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:28:25 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/11 12:05:17 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(char const *s, char c)
{
	char	*tmp;
	size_t	cnt;
	size_t	i;

	i = 1;
	tmp = (char*)s;
	cnt = (*tmp != c) ? 1 : 0;
	while (tmp[i] != 0)
	{
		if ((tmp[i] != c && tmp[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}

static int		add_str(char **to, char const *from, char c, int index)
{
	size_t	i;
	size_t	rtn;

	i = 0;
	while (from[i] != c && from[i] != 0)
		i++;
	if ((to[index] = ft_strnew(i)) == NULL)
		return (0);
	rtn = i;
	while (i-- > 0)
		to[index][i] = from[i];
	return (rtn);
}

static int		cool_add_str(char **to, char const *from, char c, int index)
{
	size_t	i;
	size_t	rtn;

	i = 0;
	while (from[i] != c && from[i] != 0)
		i++;
	if ((to[index] = cool_strnew(i)) == NULL)
		return (0);
	rtn = i;
	while (i-- > 0)
		to[index][i] = from[i];
	return (rtn);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rtn;
	size_t	i;
	int		j;
	int		add;

	if (!(rtn = (char**)malloc((word_counter(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 1;
	j = 0;
	if (*s != c)
		if ((i = add_str(rtn, s, c, j++)) == 0)
			return (NULL);
	while (s[i] != 0)
	{
		if ((s[i] != c && s[i - 1] == c))
		{
			if ((add = add_str(rtn, s + i, c, j++)) == 0)
				return (NULL);
			i += add;
		}
		else
			i++;
	}
	rtn[j] = NULL;
	return (rtn);
}

char			**cool_strsplit(char const *s, char c)
{
	char	**rtn;
	size_t	i;
	int		j;
	int		add;

	if (!(rtn = (char**)cool_malloc((word_counter(s, c) + 1) * sizeof(char*))))
		return (NULL);
	i = 1;
	j = 0;
	if (*s != c)
		if ((i = cool_add_str(rtn, s, c, j++)) == 0)
			return (NULL);
	while (s[i] != 0)
	{
		if ((s[i] != c && s[i - 1] == c))
		{
			if ((add = cool_add_str(rtn, s + i, c, j++)) == 0)
				return (NULL);
			i += add;
		}
		else
			i++;
	}
	rtn[j] = NULL;
	return (rtn);
}

