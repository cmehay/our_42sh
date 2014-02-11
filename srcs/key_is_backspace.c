/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/08 16:11:48 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <curses.h>
#include <term.h>

int	ms_key_is_backspace(t_context *ctx, t_cmd_char **cmd_char)
{
	t_cmd_char	*current;

	current = ms_get_cursor_position(cmd_char);
	if (current->prev)
	{
		if (*cmd_char == current->prev)
			*cmd_char = current;
		ms_cmd_char_lstdelone(current->prev);
		tputs(tgetstr("le", NULL), 0, ms_putchar);
		tputs(tgetstr("dc", NULL), 0, ms_putchar);
	}
	(void) ctx;
	return (0);
}
