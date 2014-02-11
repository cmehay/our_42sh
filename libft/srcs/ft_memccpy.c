/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:49:41 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:36:31 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dst_cpy;
	const char	*src_cpy;
	char		*c_ptr;
	size_t		i;

	dst_cpy = (char *) dst;
	src_cpy = (const char *) src;
	c_ptr = (char *) dst;
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		c_ptr++;
		if (src_cpy[i] == (unsigned char) c)
			return ((void *) c_ptr);
		i++;
	}
	return (NULL);
}
