/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:25:01 by cmehay            #+#    #+#             */
/*   Updated: 2013/11/24 16:31:31 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function adds char c at the end of s1 string and adds '\0'.
** s1 is returned.
*/
char	*ft_charcat(char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	s1[i] = c;
	s1[i + 1] = 0;
	return (s1);
}
