/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 15:01:39 by dcouly            #+#    #+#             */
/*   Updated: 2014/02/19 16:42:51 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

int	ms_builtin_history(t_context *ctx)
{
	t_history	*current;
	t_cmd_char	*char_c;

	current = ctx->history;
	while (current->next)
		current = current->next;
	while (current)
	{
		char_c = current->cmd_char;
		while (char_c)
		{
			ft_putchar(char_c->character);
			char_c = char_c->next;
		}
		ft_putchar('\n');
		current = current->prev;
	}
	return (0);
}
