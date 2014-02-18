/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:42:50 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/18 22:42:56 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

int		ms_builtin_echo(char **argv)
{
	int	cnt;

	cnt = 1;
	while (argv[cnt])
	{
		if (cnt != 1)
			ft_putchar(' ');
		ft_putstr(argv[cnt]);
		cnt++;
	}
	ft_putchar('\n');
	return (0);
}
