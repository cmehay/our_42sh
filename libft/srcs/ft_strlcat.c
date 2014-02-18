/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:41:45 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/17 12:28:12 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	ssize_t	catsize;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	catsize = (ssize_t) size - dst_len - 1;
	ft_strncat(dst, src, catsize * (catsize > 0));
	return (src_len + ft_min(size, dst_len));
}
