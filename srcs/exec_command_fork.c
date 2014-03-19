/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:46:33 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/19 18:02:58 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <signal.h>

static int	ms_command_exec_parent(t_context *context, t_command *cmd,
	pid_t child)
{
	if (cmd->fdin.type == IO_READLINE)
		close(cmd->fdin.pipe[PIPE_READ]);
	return (ms_command_process_add(context, child));
}

static void	exec_father(t_context *context, pid_t father)
{
	signal(SIGTTOU, SIG_DFL);
	if (context->fg[context->num_fg] == -1)
		setpgid(0, context->last_gid);
	else
		setpgid(0, 0);
	kill(father, SIGUSR1);
	pause();
}

static int	exec_child(t_context *context, t_command *cmd, pid_t child)
{
	signal(SIGTTOU, SIG_IGN);
	pause();
	kill(child, SIGUSR1);
	context->last_gid = getpgid(child);
	if (context->fg[context->num_fg++] == 0)
		tcsetpgrp(STDIN_FILENO, getpgid(child));
	if (context->fg[context->num_fg - 1] != -1)
		ms_jobs_lstadd(context, cmd->name, context->fg[context->num_fg - 1],
		child);
	else
		ms_jobs_add_cmd(cmd->name, context, child);
	return (ms_command_exec_parent(context, cmd, child));
}

int			ms_command_exec_normal(t_context *context, t_command *cmd,
	int infd, int outfd)
{
	char	*name;
	pid_t	child;
	pid_t	father;

	father = getpid();
	if (!cmd->argv[0])
		return (-1);
	name = ms_command_search(cmd->env_cpy, cmd->argv[0]);
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
	{
		exec_father(context, father);
		ms_command_exec_child(context, cmd, infd, outfd);
	}
	else
		return (exec_child(context, cmd, child));
	return (0);
}
