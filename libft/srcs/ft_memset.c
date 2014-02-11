/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:32:25 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:36:43 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *) s;
	i = 0;
	while (i < len)
		tmp[i++] = (unsigned char) c;
	return (s);
}
