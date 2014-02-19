/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 07:17:18 by cmehay            #+#    #+#             */
/*   Updated: 2013/12/18 20:47:16 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*atoi_shift(char *s)
{
	while ((*s > 8 && *s < 14) || *s == 32)
		s++;
	return (s);
}

int			ft_atoi(const char *str)
{
	char	*shift;
	size_t	i;
	int		mul;
	int		rtn;
	int		neg;

	shift = atoi_shift((char*) str);
	i = 0;
	mul = 1;
	rtn = 0;
	neg = 1 - ((shift[i] == '-') * 2);
	if (shift[i] == '-' || shift[i] == '+')
		i++;
	while (ft_isdigit(shift[i]))
		i++;
	while (i > (shift[0] == '-' || shift[0] == '+'))
	{
		rtn += (shift[i-- - 1] - 0x30) * mul;
		mul *= 10;
	}
	return (rtn * neg);
}
