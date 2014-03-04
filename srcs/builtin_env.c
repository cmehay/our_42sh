/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 18:06:04 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/04 19:42:35 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

int	ms_builtin_env(t_context *context, char **argv, int outfd)
{
	t_env	*current;

	current = context->env;
	if (argv[1] && ft_strequ(argv[1], "-u") && argv[2])
		ms_builtin_unsetenv(context, argv + 1, outfd);
	if (argv[1] && (ft_strequ(argv[1], "-i") || ft_strequ(argv[1], "-"))
		&& argv[2])
		return (1);
	while (current)
	{
		ft_putstr_fd(current->name, outfd);
		ft_putchar_fd('=', outfd);
		ft_putendl_fd(current->value, outfd);
		current = current->next;
	}
	return (0);
}
