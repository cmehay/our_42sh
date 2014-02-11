/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:51:07 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/01 19:35:39 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] <= 33 || str[i] >= 126)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	nbr = (int) str[i] - '0';
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + ((int) str[i] - '0');
		i++;
	}
	return (sign * nbr);
}
