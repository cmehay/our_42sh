/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_history_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:49:08 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 23:03:02 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

t_history	*ms_history_lstadd(t_history *history, t_cmd_char *cmd_char)
{
	t_history	*elem;

	if ((elem = (t_history *) cool_malloc(sizeof(t_history))) == NULL)
		return ((t_history *) ms_function_failed("cool_malloc failed", NULL));
	elem->cmd_char = cmd_char;
	elem->prev = NULL;
	elem->next = NULL;
	if (history == NULL)
	{
		history = elem;
		return (elem);
	}
	if (history->next)
		history->next->prev = elem;
	elem->next = history->next;
	elem->prev = history;
	history->next = elem;
	return (history);
}

void	ms_history_lstdel(t_history *history)
{
	t_history	*current;
	t_history	*next;

	current = history;
	while (current)
	{
		next = current->next;
		cool_free(current->cmd_char);
		cool_free(current);
		current = next;
	}
	current = NULL;
}
