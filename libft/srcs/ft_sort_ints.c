/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 13:02:58 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 13:52:49 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_ints(int *tab, int size)
{
	int	i;
	int	next;
	int	tmp;

	i = 0;
	while (i < size)
	{
		next = i + 1;
		while (next < size)
		{
			if (tab[i] > tab[next])
			{
				tmp = tab[i];
				tab[i] = tab[next];
				tab[next] = tmp;
			}
			next++;
		}
		i++;
	}
}
