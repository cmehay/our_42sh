/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:10:23 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/21 10:23:34 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_initmem(int size, int64_t n)
{
	char	*str;

	if (n < 0)
		size++;
	str = ft_strnew(size);
	return (str);
}

static char		*ft_charcat(char *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	s1[i] = c;
	s1[i + 1] = 0;
	return (s1);
}

static void		ft_itoa_cmp(int64_t n, char *str)
{
	uint64_t	usgn_copy;
	int64_t		nb_size;
	int64_t		nb_copy;
	int64_t		nb_print;

	if (n < 0)
		ft_charcat(str, '-');
	usgn_copy = n * ((n > 0) + (n > 0) - 1);
	nb_size = 1;
	nb_copy = usgn_copy;
	while (nb_copy / 10 > 0)
	{
		nb_size *= 10;
		nb_copy /= 10;
	}
	while (nb_size > 0)
	{
		nb_print = 0;
		nb_print = usgn_copy / nb_size;
		ft_charcat(str, nb_print + '0');
		usgn_copy = usgn_copy % nb_size;
		nb_size = nb_size / 10;
	}
}

char			*ft_itoa(int64_t n)
{
	uint64_t	usgn_cp;
	int64_t		nb_size;
	char		*rtn;

	usgn_cp = n * ((n > 0) + (n > 0) - 1);
	nb_size = 1;
	while (usgn_cp / 10 > 0)
	{
		usgn_cp /= 10;
		nb_size++;
	}
	if ((rtn = ft_initmem(nb_size, n)) != NULL)
		ft_itoa_cmp(n, rtn);
	return (rtn);
}
