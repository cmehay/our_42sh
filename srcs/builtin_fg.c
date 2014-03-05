/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:31:40 by dcouly            #+#    #+#             */
/*   Updated: 2014/03/04 17:30:53 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <signal.h>

static int	ms_print_not_found(char *argv1, int outfd)
{
	if (argv1)
	{
		ft_putstr_fd("fg : job not found: ", outfd);
		ft_putendl_fd(argv1, outfd);
	}
	else
		ft_putendl_fd("fg : job not found", outfd);
	return (0);
}

int			ms_builtin_fg(t_context *context, char **argv, int outfd)
{
	t_jobs	*current;
	int		number;
	int		opt;

	opt = 0;
	number = -1;
	if (argv[1] == 0)
		opt = 1;
	else if (argv[1][0] != '%')
		return (ms_print_not_found(argv[1], outfd));
	else
		number = ft_atoi(&argv[1][1]);
	current = context->jobs;
	while (current)
	{
		if (current->num == number || (current->next == NULL && opt == 1))
		{
			current->state = FORGROUND;
			tcsetpgrp(STDIN_FILENO, getpgid(current->pid));
			kill(current->pid, SIGCONT);
			return (0);
		}
		current = current->next;
	}
	return (ms_print_not_found(argv[1], outfd));
}
