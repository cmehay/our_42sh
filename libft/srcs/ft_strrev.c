/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 11:50:56 by sbethoua          #+#    #+#             */
/*   Updated: 2013/12/03 12:58:42 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str);
	i = 0;
	j = len - 1;
	while (i < (len / 2))
		ft_swap_chr(&str[i++], &str[j--]);
	return (str);
}
