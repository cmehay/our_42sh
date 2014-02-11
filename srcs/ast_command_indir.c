/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_command_indir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/28 19:18:34 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

t_lex		*ms_ast_lexer_command_alien_find(t_lex *lexer)
{
	t_lex	*current;

	current = lexer;
	while (current)
	{
		if (current->type != TOK_WORD)
			return (current);
		current = current->next;
	}
	return (NULL);
}

int			ms_ast_command_indir_in(t_command *cmd, t_lex *item)
{
	if (cmd->fdin.type != IO_DEFAULT)
	{
		ms_err_display("ambiguous input indirection.");
		return (-1);
	}
	cmd->fdin.type = (item->type == TOK_LT_SIGN) ? IO_FILE : IO_READLINE;
	cmd->fdin.filename = item->next->token;
	item->next->token = NULL;
	return (0);
}

int			ms_ast_command_indir_out(t_command *cmd, t_lex *item)
{
	if (cmd->fdout.type != IO_DEFAULT)
	{
		ms_err_display("ambiguous output indirection.");
		return (-1);
	}
	cmd->fdout.type = (item->type == TOK_GT_SIGN) ? IO_FILE : IO_FILE_APPEND;
	cmd->fdout.filename = item->next->token;
	item->next->token = NULL;
	return (0);
}

int			ms_ast_command_indir_add(t_command *cmd, t_lex **lexer, t_lex *item)
{
	int	ret;

	ret = 0;
	if (item->type == TOK_D_LT_SIGN || item->type == TOK_LT_SIGN)
		ret = ms_ast_command_indir_in(cmd, item);
	if (item->type == TOK_D_GT_SIGN || item->type == TOK_GT_SIGN)
		ret = ms_ast_command_indir_out(cmd, item);
	ms_lexer_lstdelone(lexer, item->next);
	ms_lexer_lstdelone(lexer, item);
	return (ret);
}

int			ms_ast_command_indir(t_command *cmd, t_lex **lexer)
{
	t_lex	*item;
	int		ret;

	ret = 0;
	item = ms_ast_lexer_command_alien_find(*lexer);
	while (item)
	{
		if (!item->next || !item->prev || item->next->type != TOK_WORD)
		{
			ms_err_display("parse error near indirection.");
			return (-1);
		}
		ret = ms_ast_command_indir_add(cmd, lexer, item);
		if (ret < 0)
			return (-1);
		item = ms_ast_lexer_command_alien_find(*lexer);
	}
	return (0);
}
