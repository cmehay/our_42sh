/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_arrow_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/08 16:16:44 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ms_cmd_char_display(t_cmd_char *cmd_char)
{
	t_cmd_char	*current;

	current = cmd_char;
	while (current)
	{
		ft_putchar(current->character);
		current = current->next;
	}
}

int		ms_key_is_arrow_up(t_context *ctx, t_cmd_char **cmd_char)
{
	if (!ctx->history)
		return (0);
	tputs(tgetstr("rc", NULL), 0, ms_putchar);
	tputs(tgetstr("cd", NULL), 0, ms_putchar);

	t_history	*current;
	current = ctx->history;
	while (current)
	{
		if (current->cmd_char == *cmd_char)
		{
			ms_cmd_char_display(current->next->cmd_char);
			return (0);
		}
		current = current->next;
	}
	ms_cmd_char_display(ctx->history->cmd_char);
	return (0);
}
