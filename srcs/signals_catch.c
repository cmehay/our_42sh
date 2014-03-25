/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_catch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 01:21:39 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/25 21:35:37 by cmehay           ###   ########.fr       */
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
}
