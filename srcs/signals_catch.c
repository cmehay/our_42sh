/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_catch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 01:21:39 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/05 01:22:06 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <signal.h>

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
