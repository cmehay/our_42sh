/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:32:58 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 22:47:49 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"

t_node	*ms_command_parse(t_context *context)
{
	t_node	*astroot;
	t_lex	*lexer;
	char	*cmd_line;
	int		ret;

	ms_term_mode_raw(context->term);
	ret = ms_command_line_get(context, STDIN_FILENO, &cmd_line);
	ms_term_mode_default(context->term);
	ft_putchar_fd('\n', STDERR_FILENO);
	if (ret < 0)
		ms_builtin_exit(context, NULL, STDOUT_FILENO);
	if (ret == 0)
		return (NULL);
	lexer = ms_command_lex(cmd_line);
	if (!lexer)
		return (NULL);
	astroot = ms_ast_build(NULL, lexer, DIR_NONE);
	return (astroot);
}
