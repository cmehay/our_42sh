/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:59:34 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 13:06:51 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_ascii(int argc, char **argv, int outset)
{
	int		next;
	char	*tmp;

	while (outset < argc)
	{
		next = outset + 1;
		while (next < argc)
		{
			if (ft_strcmp(argv[outset], argv[next]) > 0)
			{
				tmp = argv[outset];
				argv[outset] = argv[next];
				argv[next] = tmp;
			}
			next++;
		}
		outset++;
	}
	return (argv);
}
