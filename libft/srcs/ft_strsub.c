/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:55:14 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:37:40 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		ft_strncpy(str, &s[start], len);
		str[len] = '\0';
	}
	return (str);
}
