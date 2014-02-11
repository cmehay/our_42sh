/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_shift_arrow_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/08 16:17:28 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int	ms_key_is_shift_arrow_right(t_context *ctx, t_cmd_char **cmd_char)
{
	t_cmd_char	*current;

	current = ms_get_cursor_position(cmd_char);
	while (current->next && current->next->character == ' ')
	{
		ms_key_is_arrow_right(ctx, cmd_char);
		current = current->next;
	}
	while (current->next && current->next->character != ' ')
	{
		ms_key_is_arrow_right(ctx, cmd_char);
		current = current->next;
	}
	ms_key_is_arrow_right(ctx, cmd_char);
	if (!current->next)
		return (0);
	return (1);
}
