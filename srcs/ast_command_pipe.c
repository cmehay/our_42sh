/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_command_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 22:37:08 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

static t_node	*ms_ast_command_stdin_pipe_lookup(t_node *node)
{
	while (node && node->parent && node->parent->type == NODE_PIPE
			&& node->parent->left == node)
		node = node->parent;
	if (node && node->parent && node->parent->type == NODE_PIPE
		&& node->parent->right == node)
		node = node->parent;
	else
		node = NULL;
	return (node);
}

static t_node	*ms_ast_command_stdout_pipe_lookup(t_node *node)
{
	while (node && node->parent && node->parent->type == NODE_PIPE
			&& node->parent->right == node)
		node = node->parent;
	if (node && node->parent && node->parent->type == NODE_PIPE
		&& node->parent->left == node)
		node = node->parent;
	else
		node = NULL;
	return (node);
}

void			ms_ast_command_pipe(t_node *node, t_command *cmd)
{
	t_node	*tmp;

	if (node->parent && node->parent->type == NODE_PIPE)
	{
		if (node->parent->left == node)
		{
			cmd->fdout.type = IO_PIPE;
			cmd->fdout.pipenode = node->parent;
			if ((tmp = ms_ast_command_stdin_pipe_lookup(node->parent)))
			{
				cmd->fdin.type = IO_PIPE;
				cmd->fdin.pipenode = tmp;
			}
		}
		if (node->parent->right == node)
		{
			cmd->fdin.type = IO_PIPE;
			cmd->fdin.pipenode = node->parent;
			if ((tmp = ms_ast_command_stdout_pipe_lookup(node->parent)))
			{
				cmd->fdout.type = IO_PIPE;
				cmd->fdout.pipenode = tmp;
			}
		}
	}
}

