/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_cmd_char_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:19:07 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/08 16:11:41 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

t_cmd_char	*ms_cmd_char_alloc(char character)
{
	t_cmd_char	*elem;

	if ((elem = (t_cmd_char *) malloc(sizeof(t_cmd_char))) == NULL)
		return ((t_cmd_char *) ms_function_failed("malloc failed", NULL));
	elem->character = character;
	elem->cursor = FALSE;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}

t_cmd_char	*ms_cmd_char_lstadd(t_cmd_char *cmd_char, char character)
{
	t_cmd_char	*elem;
	t_cmd_char	*current;

	if ((elem = ms_cmd_char_alloc(character)) == NULL)
		return (NULL);
	if (cmd_char == NULL)
	{
		elem->cursor = TRUE;
		cmd_char = elem;
		return (elem);
	}
	current = cmd_char;
	while (current->cursor == FALSE)
		current = current->next;
	elem->prev = current->prev;
	current->prev = elem;
	elem->next = current;
	if (elem->prev)
		elem->prev->next = elem;
	if (elem->prev == NULL)
		cmd_char = elem;
	return (cmd_char);
}

void		ms_cmd_char_lstdelone(t_cmd_char *current)
{
	if (current)
	{
		if (current->prev)
			current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;
		free(current);
	}
}

void		ms_cmd_char_lstdel(t_cmd_char *cmd_char)
{
	t_cmd_char	*current;
	t_cmd_char	*next;

	current = cmd_char;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
