/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:49:58 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 21:44:25 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*cpy1;
	const char	*cpy2;
	size_t		i;

	cpy1 = (const char *) s1;
	cpy2 = (const char *) s2;
	i = 0;
	while (i < n)
	{
		if (cpy1[i] != cpy2[i])
			return ((unsigned char) cpy1[i] - (unsigned char) cpy2[i]);
		i++;
	}
	return (0);
}
