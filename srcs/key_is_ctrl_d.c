/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:24:20 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 23:00:05 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

int	ms_key_is_ctrl_d(t_context *ctx, t_cmd_char **cmd_char)
{
	ms_term_mode_default(ctx->term);
	ms_cmd_char_lstdel(cmd_char);
	ms_context_clean(ctx);
	exit(1);
	return (0);
}
