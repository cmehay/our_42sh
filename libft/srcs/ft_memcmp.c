/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:09:31 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 13:26:40 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cp;
	unsigned char	*s2_cp;
	size_t			i;

	s1_cp = (unsigned char*) s1;
	s2_cp = (unsigned char*) s2;
	i = 0;
	while ((s1_cp[i] - s2_cp[i]) == 0 && i < n - 1)
		i++;
	return ((s1_cp[i] - s2_cp[i]) * (n > 0));
}
