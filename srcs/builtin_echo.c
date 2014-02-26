/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:42:50 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/26 11:05:50 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

int		ms_builtin_echo(t_context __UNUSED__ *context, char **argv, int outfd)
{
	int	cnt;

	cnt = 1;
	while (argv[cnt])
	{
		if (cnt != 1)
			ft_putchar_fd(' ', outfd);
		ft_putstr_fd(argv[cnt], outfd);
		cnt++;
	}
	ft_putchar_fd('\n', outfd);
	return (0);
}
