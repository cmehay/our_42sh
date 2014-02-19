/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:49:13 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 08:52:02 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*s1_cp;
	const char	*s2_cp;
	size_t		i;

	s1_cp = s1;
	s2_cp = s2;
	i = 0;
	while (i < n)
	{
		*s1_cp = s2_cp[i];
		s1_cp++;
		if (s2_cp[i++] == (unsigned char) c)
			return (s1_cp);
	}
	return (NULL);
}
