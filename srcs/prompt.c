/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 23:01:47 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

static void	ms_prompt_display(t_context *context)
{
	t_env	*user;

	ft_putstr("\033[1;31m");
	if ((user = ms_var_ptr_get(context, "USER")))
		ft_putstr(user->value);
	ft_putstr("$> ");
	ft_putstr("\033[0;m");
	return ;
}

void		ms_prompt_run(t_context *context)
{
	t_node	*astroot;

	while (1)
	{
		ms_prompt_display(context);
		astroot = ms_command_parse(context);
		if (astroot)
		{
			ms_exec_tree(context, astroot);
			ms_exec_processes_wait(context);
			ms_ast_clean(astroot);
		}
	}
}
