/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_search_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 22:28:40 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/25 22:29:08 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int			ms_builtins_search_exec(t_context *context, t_command *cmd,
	int outfd)
{
	if (ft_strcmp("cd", cmd->argv[0]) == 0)
		return (ms_builtin_cd(context, cmd->argv, outfd));
	if (ft_strcmp("bg", cmd->argv[0]) == 0)
		return (ms_builtin_bg(context, cmd->argv, outfd));
	if (ft_strcmp("fg", cmd->argv[0]) == 0)
		return (ms_builtin_fg(context, cmd->argv, outfd));
	if (ft_strcmp("stop", cmd->argv[0]) == 0)
		return (ms_builtin_stop(context, cmd->argv, outfd));
	if (ft_strcmp("history", cmd->argv[0]) == 0)
		return (ms_builtin_history(context));
	if (ft_strcmp("jobs", cmd->argv[0]) == 0)
		return (ms_builtin_jobs(context, outfd));
	if (ft_strcmp("echo", cmd->argv[0]) == 0)
		return (ms_builtin_echo(context, cmd->argv, outfd));
	if (ft_strcmp("setenv", cmd->argv[0]) == 0)
		return (ms_builtin_setenv(context, cmd->argv, outfd));
	if (ft_strcmp("unsetenv", cmd->argv[0]) == 0)
		return (ms_builtin_unsetenv(context, cmd->argv, outfd));
	return (ms_builtins_search_exec2(context, cmd, outfd));
}
