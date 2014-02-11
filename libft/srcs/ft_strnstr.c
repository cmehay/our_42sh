/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:50:55 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:37:34 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] == str[i + j] && to_find[j] != '\0' && (i + j) < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *) &str[i]);
		i++;
	}
	return ((char *) NULL);
}
