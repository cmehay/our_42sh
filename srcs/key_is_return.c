/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/05 16:17:19 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"


static int	ms_nb_exec(t_cmd_char **cmd_char)
{
	t_cmd_char	*current;
	int			nb;

	current = *cmd_char;
	nb = 0;
	while (current && current->next)
	{
		if (current->character == '|' || current->character == '&')
		{
			if (current->next && (current->next->character == '|'
						|| current->next->character == '&'))
			{
				current = current->next;
				nb++;
			}
		}
		if (current->character == ';' || current->character == '|')
			nb++;
		current = current->next;
	}
	return (nb);
}

static int	ms_end_comm_part(t_cmd_char *curr)
{
	t_cmd_char	*current;

	current = curr;
	if (current->character == ';')
		return (1);
	if (current->next && current->next->character == '&'
			&& current->character == '&')
		return (1);
	if (current->next && current->next->character == '|'
			&& current->character == '|')
		return (1);
	return (0);
}

static int	ms_is_background(char last, t_cmd_char *current)
{
	if (last != '&')
		return (0);
	while (current->character != '&')
		current = current->prev;
	current->character = ' ';
	return (1);
}

static int	*ms_is_fg_comm(t_cmd_char **cmd_char)
{
	t_cmd_char	*current;
	int			last;
	int			*fg;
	int			nb_c;
	int			nb_job;

	nb_job = 1;
	nb_c = 0;
	fg = (int *) cool_malloc(sizeof(int) * ms_nb_exec(cmd_char));
	current = *cmd_char;
	while (current && current->next)
	{
		if (current->character == '|' && current->next
				&& current->next->character != '|')
			nb_job++;
		if (ms_end_comm_part(current))
		{
			fg[nb_c++] = ms_is_background(last, current);
			while (nb_job-- > 1)
				fg[nb_c++] = -1;
			nb_job = 1;
		}
		if (current->character != ' ' && current->character != '\t')
			last = current->character;
		current = current->next;
	}
	fg[nb_c++] = ms_is_background(last, current);
	while (nb_job-- > 1)
		fg[nb_c++] = -1;
	return (fg);
}

int			ms_key_is_return(t_context *ctx,
		char **cmd_line, t_cmd_char **cmd_char)
{
	ms_exec_processes_wait(ctx);
	ms_modif_jobs(ctx);
	while (ctx->history && ctx->history->prev)
		ctx->history = ctx->history->prev;
	if ((*cmd_char)->character)
		ctx->history = ms_history_lstadd(ctx->history, *cmd_char);
	ctx->fg = ms_is_fg_comm(cmd_char);
	ctx->num_fg = 0;
	if ((*cmd_char)->character == '!')
		ms_builtin_point(ctx, cmd_char);
	*cmd_line = ms_convert_list_to_str(*cmd_char);
	if (*cmd_line == NULL)
		return (ms_err_ret("cool_malloc failed", -1));
	return (1);
}
