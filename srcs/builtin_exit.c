/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:39:10 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/28 18:02:57 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>
#include <signal.h>

void	ms_kill_all(t_context *context)
{
	t_process	*proc;
	t_process	*next;

	proc = context->processes;
	while (proc)
	{
		next = proc->next;
		kill(proc->pid, SIGKILL);
		cool_free(proc);
		proc = next;
	}
}

int		ms_builtin_exit(t_context *context,
		char __UNUSED__ **argv, int __UNUSED__ outfd)
{
	ms_kill_all(context);
	ms_context_clean(context);
	exit (1);
}
