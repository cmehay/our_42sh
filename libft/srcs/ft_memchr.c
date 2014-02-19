/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:49:13 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/22 11:31:08 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cp;
	size_t	i;

	s_cp = (char*) s;
	i = 0;
	while (i < n)
	{
		if (s_cp[i++] == (unsigned char) c)
			return (s_cp + (i - 1));
	}
	return (NULL);
}
