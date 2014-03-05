/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/05 01:31:19 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static void	ms_command_exec_child_dups(int infd, int outfd)
{
	int	ret;

	if (infd != STDIN_FILENO)
	{
		ret = dup2(infd, STDIN_FILENO);
		if (ret < 0)
			exit(EXIT_FAILURE);
		close(infd);
	}
	if (outfd != STDOUT_FILENO)
	{
		ret = dup2(outfd, STDOUT_FILENO);
		if (ret < 0)
			exit(EXIT_FAILURE);
		close(outfd);
	}
}

static void	ms_command_exec_child_pipes(t_command *cmd)
{
	int	*pfd;

	if (cmd->fdin.type == IO_READLINE)
		close(cmd->fdin.pipe[PIPE_WRITE]);
	if (cmd->fdin.type == IO_PIPE)
	{
		pfd = cmd->fdin.pipenode->data;
		close(pfd[PIPE_WRITE]);
	}
	if (cmd->fdout.type == IO_PIPE)
	{
		pfd = cmd->fdout.pipenode->data;
		close(pfd[PIPE_READ]);
	}
}

void		ms_command_exec_child(t_context __UNUSED__ *context, t_command *cmd,
		int infd, int outfd)
{
	char	**env;

	ms_command_exec_child_dups(infd, outfd);
	ms_command_exec_child_pipes(cmd);
	env = ms_env_clone(cmd->env_cpy);
	if (env && !cmd->null_env)
		execve(cmd->name, cmd->argv, env);
	else
		execve(cmd->name, cmd->argv, NULL);
	exit(EXIT_FAILURE);
}
