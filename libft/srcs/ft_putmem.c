/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 14:55:43 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 16:34:18 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem(void *ptr)
{
	ft_putstr("Address: ");
	ft_putnbr((long int) ptr);
	ft_putstr("\tContent: ");
	ft_putendl(ptr);
}
