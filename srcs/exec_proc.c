/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:05:17 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/19 18:26:48 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>

static void	foreground(t_context *context, t_jobs *current, int *status)
{
	while (current->state == FORGROUND)
	{
		if (waitpid(current->pid, status, WNOHANG | WUNTRACED))
		{
			if (WIFSTOPPED(*status))
				current->state = STOPPED;
			else
				current->state = -1;
		}
	}
	tcsetpgrp(STDIN_FILENO, context->gid);
}

static void	background(t_jobs *current, int *bg)
{
	if (waitpid(current->pid, bg, WNOHANG | WUNTRACED))
	{
		if (WIFSTOPPED(*bg))
			current->state = STOPPED;
		else
			current->state = -1;
	}
}

int			ms_exec_processes_wait(t_context *context)
{
	t_jobs	*current;
	int		status;
	int		bg;

	current = context->jobs;
	while (current)
	{
		if (current->state == FORGROUND)
			foreground(context, current, &status);
		else if (current->state == BACKGROUND)
			background(current, &bg);
		else if (current->state == STOPPED)
		{
			if (waitpid(current->pid, &bg, WNOHANG))
				current->state = -1;
		}
		current = current->next;
	}
	status = (status) ? -1 : 0;
	return (status);
}
