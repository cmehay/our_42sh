/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:51:03 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:37:27 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1) + 1;
	len2 = ft_strlen(s2) + 1;
	if (len1 < n)
		n = len1;
	if (len2 < n)
		n = len2;
	return (ft_memcmp(s1, s2, n));
}
