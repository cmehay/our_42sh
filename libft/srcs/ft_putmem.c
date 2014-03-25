/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:55:43 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/25 23:55:21 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *ptr)
{
	ft_putstr("Address: ");
	ft_putnbr((long int)ptr);
	ft_putstr("\tContent: ");
	ft_putendl(ptr);
}
