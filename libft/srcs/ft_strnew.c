/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:01:54 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/11 11:46:15 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*rtn;

	rtn = (char*)ft_memalloc(sizeof(char) * (size + 1));
	return (rtn);
}


char	*cool_strnew(size_t size)
{
	char	*rtn;

	rtn = (char*)cool_malloc(sizeof(char) * (size + 1));
	return (rtn);
}
