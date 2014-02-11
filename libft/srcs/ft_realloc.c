/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 13:42:06 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/04 19:50:29 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size_o, size_t size_n)
{
	void	*new_ptr;

	new_ptr = (void *) malloc(size_o + size_n);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = ft_memcpy(new_ptr, ptr, size_n);
	free(ptr);
	return (new_ptr);
}
