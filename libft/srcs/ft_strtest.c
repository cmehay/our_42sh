/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 01:33:47 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/13 01:39:20 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function test a string with a function
*/
int	ft_strtest(char *str, int (*f)(int))
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!f((int)*(str++)))
			return (0);
	}
	return (1);
}