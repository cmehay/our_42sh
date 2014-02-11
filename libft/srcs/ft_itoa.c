/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:16:56 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/17 15:53:29 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_itoa_len(long n, size_t *div)
{
	unsigned long	abs_n;
	size_t			i;

	i = 0;
	*div = 1;
	abs_n = (n >= 0) ? n : -n;
	while (*div <= abs_n)
	{
		*div *= 10;
		i++;
	}
	if (!abs_n)
		i++;
	else
		*div /= 10;
	return (i + (n < 0));
}

void	ft_itoa_fill(char *str, long n, size_t div)
{
	unsigned long	abs_n;
	size_t			i;

	i = 0;
	if (n < 0)
		str[i++] = '-';
	abs_n = (n >= 0) ? n : -n;
	while (div > 0)
	{
		str[i++] = '0' + (abs_n / div) % 10;
		div /= 10;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	div;
	size_t	len;
	char	*str;

	len = ft_itoa_len(n, &div);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str != NULL)
		ft_itoa_fill(str, n, div);
	return (str);
}
