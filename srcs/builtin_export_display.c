/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:36:20 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/04 17:53:28 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ms_export_display(t_context __UNUSED__ *context,
	char __UNUSED__ **argv, int outfd)
{
	t_vars	*vars;

	vars = gimme_vars();
	while (vars)
	{
		if (vars->name && vars->content)
		{
			ft_putstr_fd(vars->name, outfd);
			ft_putstr_fd("=", outfd);
			ft_putendl_fd(vars->content, outfd);
		}
		vars = vars->next;
	}
	return (0);
}
