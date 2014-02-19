/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:37:25 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 23:01:21 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

t_ttype	ms_lexer_stype_match(char c)
{
	if (c == '<')
		return (TOK_LT_SIGN);
	if (c == '>')
		return (TOK_GT_SIGN);
	if (c == '&')
		return (TOK_AND);
	if (c == '|')
		return (TOK_PIPE);
	return (TOK_UNKNOWN);
}

t_ttype	ms_lexer_dtype_match(char c)
{
	if (c == '<')
		return (TOK_D_LT_SIGN);
	if (c == '>')
		return (TOK_D_GT_SIGN);
	if (c == '&')
		return (TOK_D_AND);
	if (c == '|')
		return (TOK_D_PIPE);
	return (TOK_UNKNOWN);
}

int		ms_lexer_handle_special(char **start, char **end,
		char **ptr, t_ttype *type)
{
	if (**ptr == ';')
		*type = TOK_SEMI_COL;
	else
	{
		if (*(*ptr + 1) == **ptr)
		{
			*type = ms_lexer_dtype_match(**ptr);
			(*ptr)++;
		}
		else
			*type = ms_lexer_stype_match(**ptr);
	}
	(*ptr)++;
	*end = *ptr;
	(void) start;
	return (0);
}

int		ms_lexer_handle_normal(char **start, char **end,
		char **ptr, t_ttype *type)
{
	*start = *ptr;
	if (ms_is_special(**ptr))
		return (ms_lexer_handle_special(start, end, ptr, type));
	while (ms_is_acceptable(**ptr))
		(*ptr)++;
	*end = *ptr;
	*type = TOK_WORD;
	if (*start == *ptr)
		return (-1);
	return (0);
}

int		ms_lexer_handle_quotes(char **start, char **end,
		char **ptr, t_ttype *type)
{
	(*ptr)++;
	*start = *ptr;
	while (!ms_is_quote(**ptr) && **ptr)
		(*ptr)++;
	if (**ptr != '"')
	{
		ms_err_display("non-terminated quoted string.");
		return (-1);
	}
	else
	{
		*type = TOK_WORD;
		*end = *ptr;
		(*end)++;
	}
	return (0);
}
