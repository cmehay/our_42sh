/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:43:50 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/25 15:38:58 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static void	ms_print_state(int state, int outfd)
{
	if (state == STOPPED)
		ft_putstr_fd("STOPPED", outfd);
	else if (state == FORGROUND)
		ft_putstr_fd("FORGROUND", outfd);
	else if (state == BACKGROUND)
		ft_putstr_fd("BACKGROUND", outfd);
}

int			ms_builtin_jobs(t_context *context, int outfd)
{
	t_jobs	*current;

	current = context->jobs;
	while (current)
	{
		ft_putnbr_fd(current->num, outfd);
		ft_putstr_fd(" ", outfd);
		ft_putstr_fd(current->name, outfd);
		ft_putstr_fd(" ", outfd);
		ms_print_state(current->state, outfd);
		ft_putstr_fd(" ", outfd);
		ft_putnbr_fd(current->pid, outfd);
		ft_putstr_fd("\n", outfd);
		current = current->next;
	}
	return (0);
}
