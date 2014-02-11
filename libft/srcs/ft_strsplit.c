/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:16:56 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/17 15:54:10 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strwc(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			counter++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (counter);
}

int		ft_strsubsplit(char **tab, const char *s, char c)
{
	const char	*last_start;
	size_t		item;

	item = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		last_start = s;
		while (*s != c && *s != '\0')
			s++;
		if (last_start < s)
		{
			tab[item] = ft_strsub(last_start, 0, (s - last_start));
			if (tab[item] == NULL)
			{
				while (item > 0)
					free(tab[--item]);
				return (-1);
			}
			item++;
		}
	}
	tab[item] = NULL;
	return (0);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	count;
	int		ret;

	count = ft_strwc(s, c);
	tab = (char **) malloc(sizeof(char *) * (count + 1));
	if (tab)
	{
		ret = ft_strsubsplit(tab, s, c);
		if (ret < 0)
		{
			free(tab);
			tab = NULL;
		}
	}
	return (tab);
}
