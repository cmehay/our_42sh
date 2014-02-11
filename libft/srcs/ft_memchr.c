/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:49:53 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:36:32 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*cpy;
	size_t		i;

	cpy = (const char *) s;
	i = 0;
	while (i < n)
	{
		if (cpy[i] == (unsigned char) c)
			return ((void *) &cpy[i]);
		i++;
	}
	return (NULL);
}
