/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_point_excl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 16:18:08 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/21 14:33:55 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static char	*ms_init_all(t_cmd_char **cmd_char, t_cmd_char **current_char,
		t_history **current, t_history *history)
{
	char	*command;

	*current_char = *cmd_char;
	*current_char = (*current_char)->next;
	*current = history;
	*current = (*current)->next;
	command = ms_convert_list_to_str(*current_char);
	ms_cmd_char_lstdel(cmd_char);
	*cmd_char = ms_cmd_char_lstadd(*cmd_char, '\0');
	return (command);
}

static void	ms_free_change(char **his_command, t_history **current)
{
	cool_free(*his_command);
	*current = (*current)->next;
}

int			ms_builtin_point(t_context *context, t_cmd_char **cmd_char)
{
	t_history	*current;
	t_cmd_char	*current_char;
	char		*command;
	char		*his_command;
	t_cmd_char	*c_copy;

	command = ms_init_all(cmd_char, &current_char, &current, context->history);
	while (current)
	{
		his_command = ms_convert_list_to_str(current->cmd_char);
		if (!ft_strncmp(command, his_command, ft_strlen(command)))
		{
			c_copy = current->cmd_char;
			while (c_copy)
			{
				*cmd_char = ms_cmd_char_lstadd(*cmd_char, c_copy->character);
				c_copy = c_copy->next;
			}
			cool_free(his_command);
			break ;
		}
		ms_free_change(&his_command, &current);
	}
	cool_free(command);
	return (0);
}
