/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_shift_arrow_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 23:01:04 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <curses.h>
#include <term.h>

int	ms_key_is_shift_arrow_left(t_context *ctx, t_cmd_char **cmd_char)
{
	t_cmd_char	*current;

	current = ms_get_cursor_position(cmd_char);
	while (current->prev && current->prev->character == ' ')
	{
		ms_key_is_arrow_left(ctx, cmd_char);
		current = current->prev;
	}
	while (current->prev && current->prev->character != ' ')
	{
		ms_key_is_arrow_left(ctx, cmd_char);
		current = current->prev;
	}
	if (!current->prev)
		return (0);
	return (1);
}
