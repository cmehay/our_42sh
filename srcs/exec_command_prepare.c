/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_prepare.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 16:25:26 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static void	ms_exec_reader_child(t_command *cmd)
{
	char	*line;
	int		fd;
	t_str	*l_str;

	l_str = NULL;
	close(cmd->fdin.pipe[PIPE_READ]);
	fd = cmd->fdin.pipe[PIPE_WRITE];
	while (cool_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strcmp(line, cmd->fdin.filename) == 0)
		{
			ms_str_lstdel(&l_str, fd);
			cool_free(line);
			break ;
		}
		l_str = ms_str_lstadd(line, &l_str);
		//ft_putendl_fd(line, fd);
		cool_free(line);
	}
	exit(EXIT_SUCCESS);
}

static int	ms_exec_command_io_readline_prepare(t_command *cmd, t_cmdio *cmdio)
{
	pid_t	reader;
	int		ret;

	ret = pipe(cmdio->pipe);
	if (ret >= 0)
	{
		reader = fork();
		if (reader != 0)
		{
			close(cmdio->pipe[PIPE_WRITE]);
			if (reader < 0)
				return (-1);
			ms_command_process_add(ms_context_get(), reader);
			ret = cmdio->pipe[PIPE_READ];
		}
		else
			ms_exec_reader_child(cmd);
	}
	return (ret);
}

static int	ms_exec_command_io_pipe_get(t_cmdio *cmdio, t_pipedir d)
{
	int	*pfd;

	pfd = (int *) cmdio->pipenode->data;
	return (pfd[d]);
}

int			ms_exec_command_outfd_get(t_command *cmd)
{
	int	flags;
	int	fd;

	if (cmd->fdout.type == IO_DEFAULT)
		return (STDOUT_FILENO);
	if (cmd->fdout.type == IO_PIPE)
		return (ms_exec_command_io_pipe_get(&cmd->fdout, PIPE_WRITE));
	flags = O_WRONLY | O_CREAT;
	if (cmd->fdout.type == IO_FILE)
		flags |= O_TRUNC;
	else
		flags |= O_APPEND;
	fd = open(cmd->fdout.filename, flags, 0644);
	if (fd < 0)
		ms_err_display("unable to open or create output file.");
	return (fd);
}

int			ms_exec_command_infd_get(t_command *cmd)
{
	int	fd;

	fd = -1;
	if (cmd->fdin.type == IO_DEFAULT)
		return (STDIN_FILENO);
	if (cmd->fdin.type == IO_PIPE)
		return (ms_exec_command_io_pipe_get(&cmd->fdin, PIPE_READ));
	if (cmd->fdin.type == IO_READLINE)
		return (ms_exec_command_io_readline_prepare(cmd, &cmd->fdin));
	if (cmd->fdin.type == IO_FILE)
	{
		fd = open(cmd->fdin.filename, O_RDONLY);
		if (fd < 0)
			ms_err_display("unable to open input file.");
	}
	return (fd);
}
