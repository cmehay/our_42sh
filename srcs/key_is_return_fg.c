/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_return_fg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 18:28:46 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/21 10:28:01 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

static int	*ms_is_fg_comm_seg(t_cmd_char *current, int *fg, int nb_c,
	int nb_job)
{
	int	last;

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

int			*ms_is_fg_comm(t_cmd_char **cmd_char)
{
	t_cmd_char	*current;
	int			*fg;
	int			nb_c;
	int			nb_job;

	nb_job = 1;
	nb_c = 0;
	fg = (int *) cool_malloc(sizeof(int) * (ms_nb_exec(cmd_char) + 1));
	current = *cmd_char;
	return (ms_is_fg_comm_seg(current, fg, nb_c, nb_job));
}
