/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:10:27 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/05 01:23:10 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <termios.h>

void	ms_signal_killall(int __UNUSED__ sig)
{
	t_context	*context;
	t_jobs		*job;

	context = ms_context_get();
	job = context->jobs;
	if (job == NULL)
	{
		context->fd = dup(STDIN_FILENO);
		close(STDIN_FILENO);
	}
	else
	{
		while (job)
		{
			if (job->state != FORGROUND)
				job = job->next;
			else
				break ;
		}
		if (job)
			kill(job->pid, SIGINT);
		ft_putchar('\n');
	}
}

void	ms_signal_win_resize(int __UNUSED__ sig)
{
	t_context		*context;
	struct winsize	ws;
	int				ret;

	context = ms_context_get();
	ret = ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (ret >= 0)
	{
		context->term->nb_columns = ws.ws_col;
		context->term->nb_lines = ws.ws_row;
	}
}

void	ms_signal_exit(int __UNUSED__ sig)
{
	t_context	*context;

	context = ms_context_get();
	ms_term_mode_default(context->term);
	ms_context_clean(context);
	exit(1);
}

void	ms_signal_stp(int __UNUSED__ sig)
{
	t_context	*context;
	int			pid;
	t_jobs		*current;

	pid = 0;
	context = ms_context_get();
	current = context->jobs;
	while (current)
	{
		if (current->state == FORGROUND)
		{
			pid = current->pid;
			current->state = STOPPED;
			break ;
		}
		current = current->next;
	}
	if (pid)
		kill(pid, SIGTSTP);
}

void	ms_nothing(int __UNUSED__ sig)
{
	(void)sig;
}
