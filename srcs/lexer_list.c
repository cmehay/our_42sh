/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:25:56 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/24 19:46:31 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

static t_lex	*ms_lex_lst_last_get(t_lex *list)
{
	t_lex	*curr;

	curr = list;
	while (curr && curr->next)
		curr = curr->next;
	return (curr);
}

t_lex			*ms_lex_lstadd(t_lex **list, char *token, t_ttype type)
{
	t_lex	*item;
	t_lex	*last;

	item = (t_lex *) cool_malloc(sizeof(t_lex));
	if (!item)
	{
		ms_err_display("cool_malloc failed.");
		return (NULL);
	}
	item->token = token;
	item->type = type;
	item->next = NULL;
	item->prev = NULL;
	if (!*list)
		*list = item;
	else
	{
		last = ms_lex_lst_last_get(*list);
		item->prev = last;
		last->next = item;
	}
	return (item);
}

void			ms_lexer_lstdelone(t_lex **list, t_lex *item)
{
	if (*list == item)
		*list = item->next;
	if (item->prev)
		item->prev->next = item->next;
	if (item->next)
		item->next->prev = item->prev;
	cool_free(item->token);
	cool_free(item);
}

void			ms_lexer_lstdel(t_lex **list)
{
	t_lex	*tmp;
	t_lex	*item;

	item = *list;
	while (item)
	{
		tmp = item->next;
		cool_free(item->token);
		cool_free(item);
		item = tmp;
	}
	*list = NULL;
}
