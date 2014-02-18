/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/29 18:13:47 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ms_command_process_add(t_context *context, pid_t child)
{
	t_process	*proc;
	t_process	*curr;

	proc = (t_process *) cool_malloc(sizeof(t_process));
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

int		ms_command_exec_parent(t_context *context, t_command *cmd, pid_t child)
{
	if (cmd->fdin.type == IO_READLINE)
		close(cmd->fdin.pipe[PIPE_READ]);
	return (ms_command_process_add(context, child));
}

int		ms_command_exec_normal(t_context *context, t_command *cmd,
		int infd, int outfd)
{
	char	*name;
	pid_t	child;

	name = ms_command_search(context, cmd->argv[0]);
	if (!name)
		return (-1);
	cmd->name = name;
	child = fork();
	if (child < 0)
	{
		ms_err_display("fork failed.");
		return (-1);
	}
	if (!child)
		ms_command_exec_child(context, cmd, infd, outfd);
	else
		return (ms_command_exec_parent(context, cmd, child));
	return (0);
}

int		ms_exec_command(t_context *context, t_node *node)
{
	t_command	*cmd;
	int			outfd;
	int			infd;
	int			ret;

	cmd = (t_command *) node->data;
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
	ret = ms_builtins_search_exec(context, cmd->argv, outfd);
	if (ret < 0)
		ret = ms_command_exec_normal(context, cmd, infd, outfd);
	if (outfd != STDOUT_FILENO)
		close(outfd);
	if (infd != STDIN_FILENO)
		close(infd);
	return (ret);
}
