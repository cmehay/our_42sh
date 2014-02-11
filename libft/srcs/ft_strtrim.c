/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:36:28 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 20:43:46 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '\0')
		return (NULL);
	while (ft_isspace(s[len - 1]))
		len--;
	len -= i;
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		str = ft_strncpy(str, &s[i], len);
		str[len] = '\0';
	}
	return (str);
}
