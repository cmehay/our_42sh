/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 18:59:00 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/04 20:42:58 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>
#include <termios.h>
#include <term.h>

static void	ms_capabilities_load(t_term *term)
{
	term->cap.str_clear = tgetstr("cl", NULL);
	term->cap.str_key_up = tgetstr("ku", NULL);
	term->cap.str_key_down = tgetstr("kd", NULL);
	term->cap.str_key_left = tgetstr("kl", NULL);
	term->cap.str_key_right = tgetstr("kr", NULL);
	term->cap.str_key_backspace = tgetstr("kb", NULL);
	term->cap.str_cursor_down = tgetstr("do", NULL);
	term->cap.str_cursor_up = tgetstr("up", NULL);
	term->cap.str_cursor_left = tgetstr("le", NULL);
	term->cap.str_cursor_right = tgetstr("nd", NULL);
	term->cap.str_cursor_move = tgetstr("cm", NULL);
}

void		ms_term_mode_raw(t_term *term)
{
	struct termios	attr;

	tgetent(NULL, getenv("TERM"));
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~(ECHO | ICANON);
	attr.c_cc[VMIN] = 1;
	attr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &attr);
	term->nb_columns = tgetnum("co");
	term->nb_lines = tgetnum("li");
	ms_capabilities_load(term);
}

void		ms_term_mode_default(t_term *term)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag |= (ECHO | ICANON);
	attr.c_oflag |= (OPOST);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &attr);
	term->nb_columns = 0;
	term->nb_lines = 0;
}
