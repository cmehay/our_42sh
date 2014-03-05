/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_arrow_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/04 20:45:00 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <term.h>

int	ms_key_is_arrow_left(t_context __UNUSED__ *ctx, t_cmd_char **cmd_char)
{
	t_cmd_char	*current;

	current = ms_get_cursor_position(cmd_char);
	if (current->prev)
	{
		current->cursor = FALSE;
		current->prev->cursor = TRUE;
	}
	else
		return (0);
	return (1);
}
