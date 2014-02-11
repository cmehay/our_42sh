/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 19:01:36 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/22 20:45:14 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

t_node	*ms_ast_build(t_node *parent, t_lex *lexer, t_direction dir)
{
	t_lex	*item;

	if (!lexer)
		return (NULL);
	item = ms_ast_lexer_find(lexer, TOK_SEMI_COL);
	if (item)
		return (ms_ast_build_semicol(lexer, item, parent, dir));
	item = ms_ast_lexer_find(lexer, TOK_D_AND);
	if (item)
		return (ms_ast_build_and(lexer, item, parent, dir));
	item = ms_ast_lexer_find(lexer, TOK_D_PIPE);
	if (item)
		return (ms_ast_build_or(lexer, item, parent, dir));
	item = ms_ast_lexer_find(lexer, TOK_PIPE);
	if (item)
		return (ms_ast_build_pipe(lexer, item, parent, dir));
	return (ms_ast_build_command(lexer, parent, dir));
}
