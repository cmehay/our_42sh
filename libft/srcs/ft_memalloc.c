/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:50:30 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/21 13:50:12 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*rtn;
	size_t	i;

	i = 0;
	if ((rtn = malloc(sizeof(char) * size)) != NULL)
	{
		while (i < size)
			rtn[i++] = 0;
	}
	return (rtn);
}
