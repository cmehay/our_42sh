/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:39:17 by cmehay            #+#    #+#             */
/*   Updated: 2014/02/13 01:41:42 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **array)
{
	char	**tmp;

	tmp = array;
	while (*array)
		free(*(array++));
	free(tmp);
}

void	cool_arraydel(char **array)
{
	char	**tmp;

	tmp = array;
	while (*array)
		cool_free(*(array++));
	cool_free(tmp);
}
