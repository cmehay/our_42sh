/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:10:27 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/28 18:07:44 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termcap.h>
#include <termios.h>

static void	ms_signal_killall(int sig)
{
	t_context	*context;
	t_process	*proc;

	context = ms_context_get();
	proc = context->processes;
	if (proc == NULL)
	{
		context->fd = dup(STDIN_FILENO);
		close(STDIN_FILENO);
	}
	else
	{
		while (proc)
		{
			kill(proc->pid, sig);
			proc = proc->next;
		}
		ft_putchar('\n');
	}
}

static void	ms_signal_win_resize(int __UNUSED__ sig)
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

static void	ms_signal_exit(int __UNUSED__ sig)
{
	t_context	*context;

	context = ms_context_get();
	ms_term_mode_default(context->term);
	ms_context_clean(context);
	exit(1);
}

static void	ms_signal_stp(int __UNUSED__ sig)
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

static void	ms_nothing(int __UNUSED__ sig)
{
	(void) sig;
}

void		ms_signal_catch(void)
{
	signal(SIGINT, ms_signal_killall);
	signal(SIGWINCH, ms_signal_win_resize);
	signal(SIGTSTP, ms_signal_stp);
	signal(SIGCONT, SIG_IGN);
	signal(SIGUSR1, ms_nothing);
	signal(SIGQUIT, ms_signal_exit);
	/*
	signal(SIGSEGV, ms_signal_exit);
	signal(SIGTERM, ms_signal_exit);
	signal(SIGHUP, ms_signal_exit);
	signal(SIGUSR1, ms_signal_exit);
	signal(SIGUSR2, ms_signal_exit);
	signal(SIGALRM, ms_signal_exit);
	signal(SIGBUS, ms_signal_exit);
	signal(SIGFPE, ms_signal_exit);
	signal(SIGILL, ms_signal_exit);
	signal(SIGPIPE, ms_signal_exit);
	signal(SIGPROF, ms_signal_exit);
	signal(SIGSYS, ms_signal_exit);
	signal(SIGVTALRM, ms_signal_exit);
	signal(SIGXCPU, ms_signal_exit);
	signal(SIGXFSZ, ms_signal_exit);
	signal(SIGTRAP, ms_signal_exit);
	signal(SIGABRT, ms_signal_exit);
	*/
}
