/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 23:00:47 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

int	ms_key_is_return(t_context *ctx, char **cmd_line, t_cmd_char **cmd_char)
{
	while (ctx->history && ctx->history->prev)
		ctx->history = ctx->history->prev;
	*cmd_line = ms_convert_list_to_str(*cmd_char);
	if (*cmd_line == NULL)
		return (ms_err_ret("cool_malloc failed", -1));
	if (ft_strcmp(*cmd_line, ""))
		ctx->history = ms_history_lstadd(ctx->history, *cmd_char);
	return (1);
}
