/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 22:30:19 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

void	ms_ast_command_clean(void *data)
{
	t_command	*command;
	int			i;

	command = (t_command *) data;
	if (command->name)
		cool_free(command->name);
	if (command->argv)
	{
		i = 0;
		while (command->argv[i])
			cool_free(command->argv[i++]);
		cool_free(command->argv);
	}
	if (command->fdin.filename)
		cool_free(command->fdin.filename);
	if (command->fdout.filename)
		cool_free(command->fdout.filename);
	cool_free(command);
}

void	ms_ast_command_io_init(t_cmdio *cmdio)
{
	cmdio->type = IO_DEFAULT;
	cmdio->filename = NULL;
	cmdio->pipenode = NULL;
}

t_node	*ms_ast_command_alloc(t_node *parent, t_direction dir)
{
	t_node		*node;
	t_command	*cmd;

	node = ms_ast_node_alloc(parent, dir, NODE_COMMAND);
	{
		cmd = (t_command *) cool_malloc(sizeof(t_command));
		if (!cmd)
			ms_ast_node_clean(&node);
		else
		{
			cmd->name = NULL;
			cmd->argv = NULL;
			ms_ast_command_io_init(&cmd->fdin);
			ms_ast_command_io_init(&cmd->fdout);
			node->data = cmd;
			node->cleanup = ms_ast_command_clean;
		}
	}
	return (node);
}

int		ms_ast_command_fill(t_node **node, t_lex *lexer)
{
	t_command	*cmd;
	int			ret;

	cmd = (t_command *) (*node)->data;
	ms_ast_command_pipe(*node, cmd);
	ret = ms_ast_command_indir(cmd, &lexer);
	if (ret < 0)
	{
		ms_lexer_lstdel(&lexer);
		return (-1);
	}
	ret = ms_ast_command_args(cmd, lexer);
	ms_lexer_lstdel(&lexer);
	if (ret < 0)
		return (-1);
	return (0);
}

t_node	*ms_ast_build_command(t_lex *lexer, t_node *parent, t_direction dir)
{
	t_node	*node;
	int		ret;

	if (ms_ast_lexer_is_alien(lexer))
	{
		ms_lexer_lstdel(&lexer);
		ms_err_display("alien spotted in command.");
		return (NULL);
	}
	node = ms_ast_command_alloc(parent, dir);
	if (node)
	{
		ret = ms_ast_command_fill(&node, lexer);
		if (ret < 0)
			ms_ast_node_clean(&node);
	}
	return (node);
}
