/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 20:20:23 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/19 18:21:19 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static int	ms_exec_semicol(t_context *context, t_node *node)
{
	int	ret;

	ms_exec_tree(context, node->left);
	ms_exec_processes_wait(context);
	ret = ms_exec_tree(context, node->right);
	return (ret);
}

static int	ms_exec_and(t_context *context, t_node *node)
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

static int	ms_exec_or(t_context *context, t_node *node)
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
	int			ret;
	t_command	*cmd;

	ret = 0;
	if (node->type == NODE_COMMAND)
	{
		cmd = (t_command*)node->data;
		cmd->env_cpy = ms_env_copy(context->env, NULL);
		ret = ms_exec_command(context, node);
	}
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
