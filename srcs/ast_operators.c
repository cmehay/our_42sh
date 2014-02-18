/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/22 20:45:14 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static t_node	*ms_ast_build_children(t_node *node, t_lex *llexer, t_lex *item)
{
	t_lex	*rlexer;

	rlexer = ms_ast_lexer_split(item);
	node->left = ms_ast_build(node, llexer, DIR_LEFT);
	if (!node->left)
	{
		ms_lexer_lstdel(&rlexer);
		ms_ast_node_clean(&node);
	}
	else
	{
		node->right = ms_ast_build(node, rlexer, DIR_RIGHT);
		if (!node->right)
		{
			ms_ast_clean(node->left);
			ms_ast_node_clean(&node);
		}
	}
	return (node);
}

t_node			*ms_ast_build_semicol(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir)
{
	t_node	*node;

	if (!item->prev || !item->next || item->next->type == TOK_SEMI_COL)
	{
		ms_lexer_lstdelone(&llexer, item);
		return (ms_ast_build(parent, llexer, dir));
	}
	node = ms_ast_node_alloc(parent, dir, NODE_SEMI_COL);
	if (node)
		node = ms_ast_build_children(node, llexer, item);
	else
		ms_lexer_lstdel(&llexer);
	return (node);
}

t_node			*ms_ast_build_and(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir)
{
	t_node	*node;

	if (!item->prev || !item->next)
	{
		ms_lexer_lstdel(&llexer);
		ms_err_display("parse error near &&.");
		return (NULL);
	}
	node = ms_ast_node_alloc(parent, dir, NODE_AND);
	if (node)
		node = ms_ast_build_children(node, llexer, item);
	else
		ms_lexer_lstdel(&llexer);
	return (node);
}

t_node			*ms_ast_build_or(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir)
{
	t_node	*node;

	if (!item->prev || !item->next)
	{
		ms_lexer_lstdel(&llexer);
		ms_err_display("parse error near ||.");
		return (NULL);
	}
	node = ms_ast_node_alloc(parent, dir, NODE_OR);
	if (node)
		node = ms_ast_build_children(node, llexer, item);
	else
		ms_lexer_lstdel(&llexer);
	return (node);
}

t_node			*ms_ast_build_pipe(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir)
{
	t_node	*node;

	if (!item->prev || !item->next)
	{
		ms_lexer_lstdel(&llexer);
		ms_err_display("parse error near pipe.");
		return (NULL);
	}
	node = ms_ast_node_alloc(parent, dir, NODE_PIPE);
	if (node)
		node = ms_ast_build_children(node, llexer, item);
	else
		ms_lexer_lstdel(&llexer);
	return (node);
}
