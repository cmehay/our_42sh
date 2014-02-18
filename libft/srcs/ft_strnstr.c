/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:59:37 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/26 12:25:19 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2_len;
	size_t	i;

	s2_len = ft_strlen(s2);
	if (s2_len == 0 || n == 0)
		return ((char*) s1);
	i = 0;
	while (*s1 != 0 && i < n && (i + s2_len <= n))
	{
		if (ft_memcmp(s1, s2, s2_len) == 0)
			return ((char*) s1);
		s1++;
		i++;
	}
	return (NULL);
}
