/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinpath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 18:51:11 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/13 19:35:45 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinpath(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len1;
	char	*str;

	len1 = ft_strlen(s1);
	len = len1 + ft_strlen(s2) + 1;
	str = (char*)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	str[len1] = '/';
	ft_strcpy(&str[len1 + 1], s2);
	return (str);
}
