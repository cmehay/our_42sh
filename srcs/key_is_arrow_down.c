/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_arrow_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/04 20:45:13 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <term.h>

int	ms_key_is_arrow_down(t_context *ctx, t_cmd_char **cmd_char)
{
	t_history	*current;
	t_cmd_char	*curr_char;

	if (!ctx->history)
		return (0);
	if (ctx->history->prev)
		ctx->history = ctx->history->prev;
	current = ctx->history;
	if (current->cmd_char->character == 0)
		curr_char = ms_keep_memory(NULL, 0);
	else
		curr_char = current->cmd_char;
	if (*cmd_char)
		ms_cmd_char_lstdel(cmd_char);
	*cmd_char = ms_cmd_char_lstadd(*cmd_char, '\0');
	while (curr_char)
	{
		if (curr_char->character == 0)
			break ;
		*cmd_char = ms_cmd_char_lstadd(*cmd_char, curr_char->character);
		curr_char = curr_char->next;
	}
	return (0);
}
