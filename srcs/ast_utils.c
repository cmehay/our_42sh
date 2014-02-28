/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/24 17:20:38 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

size_t	ms_ast_lexer_count(t_lex *lexer)
{
	size_t	size;
	t_lex	*current;

	size = 0;
	current = lexer;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int		ms_ast_lexer_is_alien(t_lex *lexer)
{
	t_lex	*curr;

	curr = lexer;
	while (curr)
	{
		if (curr->type != TOK_WORD
			&& curr->type != TOK_D_GT_SIGN && curr->type != TOK_LT_SIGN
			&& curr->type != TOK_D_LT_SIGN && curr->type != TOK_GT_SIGN)
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	ms_ast_clean(t_node *node)
{
	if (node->left)
		ms_ast_clean(node->left);
	if (node->right)
		ms_ast_clean(node->right);
	ms_ast_node_clean(&node);
}

t_lex	*ms_ast_lexer_find(t_lex *lexer, t_ttype type)
{
	t_lex	*current;

	current = lexer;
	while (current)
	{
		if (current->type == type)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_lex	*ms_ast_lexer_split(t_lex *item)
{
	t_lex	*right_lexer;

	right_lexer = item->next;
	item->prev->next = NULL;
	item->next->prev = NULL;
	cool_free(item->token);
	cool_free(item);
	return (right_lexer);
}
