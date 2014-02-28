/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/28 18:07:40 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int		ms_exec_processes_wait(t_context *context)
{
	t_jobs	*current;
	int		status[1];
	int		bg[1];

	current = context->jobs;
	while (current)
	{
		if (current->state == FORGROUND)
		{
			while (current->state == FORGROUND)
			{
				if (waitpid(current->pid, status, WNOHANG | WUNTRACED))
				{
					if (WIFSTOPPED(status))
						current->state = STOPPED;
					else
						current->state = -1;
				}
			}
			tcsetpgrp(STDIN_FILENO, context->gid);
		}
		else if (current->state == BACKGROUND)
		{
			if (waitpid(current->pid, bg, WNOHANG | WUNTRACED))
			{
				if (WIFSTOPPED(bg))
					current->state = STOPPED;
				else
					current->state = -1;
			}
		}
		current = current->next;
	}
	status[0] = (status[0]) ? -1 : 0;
	return (status[0]);
}

int		ms_exec_semicol(t_context *context, t_node *node)
{
	int	ret;

	ms_exec_tree(context, node->left);
	ms_exec_processes_wait(context);
	ret = ms_exec_tree(context, node->right);
	return (ret);
}

int		ms_exec_and(t_context *context, t_node *node)
{
	int	ret1;
	int	ret2;

	ret1 = ms_exec_tree(context, node->left);
	ret2 = ms_exec_processes_wait(context);
	if (ret2 < 0)
		ret1 = ret2;
	if (ret1 >= 0)
		ret1 = ms_exec_tree(context, node->right);
	return (ret1);
}

int		ms_exec_or(t_context *context, t_node *node)
{
	int	ret1;
	int	ret2;

	ret1 = ms_exec_tree(context, node->left);
	ret2 = ms_exec_processes_wait(context);
	if (ret2 < 0)
		ret1 = ret2;
	if (ret1 < 0)
		ret1 = ms_exec_tree(context, node->right);
	return (ret1);
}

int		ms_exec_tree(t_context *context, t_node *node)
{
	int	ret;

	ret = 0;
	if (node->type == NODE_COMMAND)
		ret = ms_exec_command(context, node);
	if (node->type == NODE_PIPE)
		ret = ms_exec_pipe(context, node);
	if (node->type == NODE_AND)
		ret = ms_exec_and(context, node);
	if (node->type == NODE_OR)
		ret = ms_exec_or(context, node);
	if (node->type == NODE_SEMI_COL)
		ret = ms_exec_semicol(context, node);
	return (ret);
}
