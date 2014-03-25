/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/25 23:47:11 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <signal.h>

int	ms_command_process_add(t_context *context, pid_t child)
{
	t_process	*proc;
	t_process	*curr;

	proc = (t_process*)cool_malloc(sizeof(t_process));
	if (!proc)
		return (-1);
	proc->pid = child;
	proc->next = NULL;
	if (!context->processes)
	{
		context->processes = proc;
		return (0);
	}
	curr = context->processes;
	while (curr->next)
		curr = curr->next;
	curr->next = proc;
	return (0);
}

int	ms_exec_command(t_context *context, t_node *node)
{
	t_command	*cmd;
	int			outfd;
	int			infd;
	int			ret;

	cmd = (t_command*)node->data;
	outfd = ms_exec_command_outfd_get(cmd);
	if (outfd < 0)
		return (-1);
	infd = ms_exec_command_infd_get(cmd);
	if (infd < 0)
	{
		if (outfd != STDOUT_FILENO)
			close(outfd);
		return (-1);
	}
	looking_for_vars_in_array(cmd->argv, context);
	ret = ms_builtins_search_exec(context, cmd, outfd);
	if (ret < 0)
		ret = ms_command_exec_normal(context, cmd, infd, outfd);
	if (outfd != STDOUT_FILENO)
		close(outfd);
	if (infd != STDIN_FILENO)
		close(infd);
	return (ret);
}
