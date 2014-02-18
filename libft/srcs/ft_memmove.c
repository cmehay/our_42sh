/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:49:13 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 08:52:18 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*s1_cp;
	const char	*s2_cp;
	size_t		i;

	s1_cp = s1;
	s2_cp = s2;
	i = 0;
	if (s1_cp < s2_cp)
	{
		while (i++ < n)
			s1_cp[i - 1] = s2_cp[i - 1];
	}
	else
	{
		while (n-- > 0)
			s1_cp[n] = s2_cp[n];
	}
	return (s1);
}
