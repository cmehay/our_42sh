/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:49:08 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/25 03:00:43 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>

t_cmd_char	*ms_get_cursor_position(t_cmd_char **cmd_char)
{
	t_cmd_char	*current;

	current = *cmd_char;
	while (current)
	{
		if (current->cursor == _TRUE)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

char		*ms_convert_list_to_str(t_cmd_char *cmd_char)
{
	int			count;
	int			i;
	t_cmd_char	*current;
	char		*cmd_line;

	count = 0;
	current = cmd_char;
	while (current)
	{
		count++;
		current = current->next;
	}
	if ((cmd_line = cool_malloc(sizeof(char) * (count))) == NULL)
		return ((char *) ms_function_failed("cool_malloc failed", NULL));
	i = 0;
	current = cmd_char;
	while (i < count)
	{
		cmd_line[i] = (current->character);
		i++;
		current = current->next;
	}
	return (cmd_line);
}

static int	ms_ctrl_c_catched(t_context *ctx)
{
	dup2(ctx->fd, STDIN_FILENO);
	return (0);
}

int			ms_command_line_get(t_context *ctx, int fd, char **cmd_line)
{
	uint64_t	key;
	t_cmd_char	*cmd_char;

	tputs(tgetstr("sc", NULL), 0, ms_putchar);
	if (tgetflag("am") == -1 || tgetflag("bw") == -1)
		ft_putstr("error");
	if ((cmd_char = ms_cmd_char_lstadd(NULL, '\0')) == NULL)
		return (ms_err_ret("cool_malloc failed", -1));
	while (1)
	{
		key = 0;
		if (read(fd, &key, 6) == -1)
			return (ms_ctrl_c_catched(ctx));
		if (key == KEY_IS_RETURN)
			return (ms_key_is_return(ctx, cmd_line, &cmd_char));
		ms_clean_line(&cmd_char, ms_prompt_len(ctx), key);
		ms_key_lookup(ctx, key, &cmd_char);
		if (ft_isprint(key))
		{
			if ((cmd_char = ms_cmd_char_lstadd(cmd_char, key)) == NULL)
				return (ms_err_ret("cool_malloc failed", -1));
		}
		ms_print_line(&cmd_char);
	}
	return (-1);
}
