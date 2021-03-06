/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_arrow_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/04 20:44:29 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <term.h>

void		ms_cmd_char_display(t_cmd_char *cmd_char)
{
	t_cmd_char	*current;

	current = cmd_char;
	while (current)
	{
		ft_putchar(current->character);
		current = current->next;
	}
}

t_cmd_char	*ms_keep_memory(t_cmd_char *cmd_char, int opt)
{
	static t_cmd_char	*mem = NULL;
	t_cmd_char			*current;

	if (opt)
	{
		if (mem != NULL)
			ms_cmd_char_lstdel(&mem);
		mem = ms_cmd_char_lstadd(mem, '\0');
		current = cmd_char;
		while (current)
		{
			mem = ms_cmd_char_lstadd(mem, current->character);
			current = current->next;
		}
		return (NULL);
	}
	else
	{
		return (mem);
	}
}

int			ms_key_is_arrow_up(t_context *ctx, t_cmd_char **cmd_char)
{
	t_history	*current;
	t_cmd_char	*curr_char;

	if (!ctx->history)
		return (0);
	if (!ctx->history->prev)
		ms_keep_memory(*cmd_char, 1);
	if (ctx->history->next)
		ctx->history = ctx->history->next;
	current = ctx->history;
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
