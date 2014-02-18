/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_arrow_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/24 12:07:55 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int	ms_key_is_arrow_right(t_context *ctx, t_cmd_char **cmd_char)
{
	t_cap		*cap;
	t_cmd_char	*current;

	cap = &(ctx->term->cap);
	current = ms_get_cursor_position(cmd_char);
	if (current->next)
	{
		tputs(cap->str_cursor_right, STDIN_FILENO, ms_putchar);
		current->cursor = _FALSE;
		current->next->cursor = _TRUE;
	}
	else
		return (0);
	return (1);
}
