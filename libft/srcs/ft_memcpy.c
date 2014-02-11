/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:49:37 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:36:37 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy1;
	const char	*cpy2;
	size_t		i;

	cpy1 = (char *) dst;
	cpy2 = (const char *) src;
	i = 0;
	while (i < n)
	{
		cpy1[i] = cpy2[i];
		i++;
	}
	return (dst);
}
