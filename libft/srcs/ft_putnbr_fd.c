/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:50:25 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 15:19:14 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long n, int fd)
{
	long	abs_n;
	long	div;
	long	tmp;

	div = 1;
	abs_n = (n >= 0) ? n : -n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (abs_n >= (10 * div))
		div *= 10;
	while (div > 0)
	{
		tmp = (abs_n / div) % 10;
		ft_putchar_fd('0' + tmp, fd);
		div /= 10;
	}
}
