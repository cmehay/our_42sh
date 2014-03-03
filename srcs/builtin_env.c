/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/01/20 18:06:04 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/02 18:02:01 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

int	ms_builtin_env(t_context *context, char __UNUSED__ **argv, int outfd)
{
	t_env	*current;

	current = context->env;
	while (current)
	{
		ft_putstr_fd(current->name, outfd);
		ft_putchar_fd('=', outfd);
		ft_putendl_fd(current->value, outfd);
		current = current->next;
	}
	return (0);
}
