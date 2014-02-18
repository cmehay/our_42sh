/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:59:37 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 13:46:01 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	s2_len;

	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char*) s1);
	while (*s1 != 0)
	{
		if (ft_memcmp(s1, s2, s2_len) == 0)
			return ((char*) s1);
		s1++;
	}
	return (NULL);
}
