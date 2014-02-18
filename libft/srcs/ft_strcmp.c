/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/19 14:16:04 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/23 11:44:41 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	comp1;
	unsigned char	comp2;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0'))
		i++;
	comp1 = s1[i];
	comp2 = s2[i];
	return (comp1 - comp2);
}
