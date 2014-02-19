/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:49:13 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 08:51:34 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1_cp;
	const char	*s2_cp;
	size_t		i;

	s1_cp = s1;
	s2_cp = s2;
	i = 0;
	while (i < n)
	{
		s1_cp[i] = s2_cp[i];
		i++;
	}
	return (s1);
}
