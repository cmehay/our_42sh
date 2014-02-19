/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:09:01 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 09:56:01 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	int		swch;
	size_t	i;

	swch = 0;
	i = 0;
	while (i < n)
	{
		if (s2[i] != 0 || swch == 0)
		{
			s1[i] = s2[i];
		}
		else
		{
			s1[i] = 0;
			swch = 1;
		}
		i++;
	}
	return (s1);
}
