/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:03:08 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/22 15:50:43 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <unistd.h>
#include <term.h>
#include <curses.h>
#include <sys/ioctl.h>

void	ft_fenetre_size(int *len, int *wid)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	*len = w.ws_row;
	*wid = w.ws_col;
}

void	ms_clean_line(t_cmd_char **cmd_char, int len, uint64_t nb)
{
	int			wid;
	int			nb_c;
	t_cmd_char	*current;

	ft_fenetre_size(&nb_c, &wid);
	nb_c = 0;
	current = *cmd_char;
	while (current)
	{
		nb_c++;
		if (current->cursor == _TRUE)
			break ;
		current = current->next;
	}
	(void) nb;
	nb_c = nb_c + (current->next != 0);
	nb_c = nb_c + len - 2;
	tputs(tgetstr("cr", NULL), 0, ms_putchar);
	nb_c = nb_c / wid;
	while (nb_c-- > 0)
		tputs(tgetstr("up", NULL), 0, ms_putchar);
	while (len-- > 0)
		tputs(tgetstr("nd", NULL), 1, ms_putchar);
	tputs(tgetstr("cd", NULL), 0, ms_putchar);
}

void	ms_print_line(t_cmd_char **cmd_char)
{
	t_cmd_char	*current;
	int			found;

	found = 0;
	current = *cmd_char;
	while (current)
	{
		write(1, &(current->character), 1);
		current = current->next;
	}
	current = *cmd_char;
	if (current->cursor == _TRUE)
		found = 1;
	while (current)
	{
		if (found && current->next != NULL)
			tputs(tgetstr("le", NULL), 1, ms_putchar);
		if (current->next != NULL && current->next->cursor == _TRUE)
			found = 1;
		current = current->next;
	}
}
