/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:37:25 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/18 22:46:32 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include "libft.h"
#include <stdlib.h>

static int	ms_lexer_skip_spaces(char **ptr)
{
	if (!**ptr)
		return (0);
	while (ms_is_space(**ptr))
		(*ptr)++;
	if (!**ptr)
		return (0);
	return (1);
}

static int	ms_lexer_token_get_next(char **cmd, char **token, t_ttype *type)
{
	char	*ptr;
	char	*start;
	char	*end;
	int		ret;

	ptr = *cmd;
	if (!ms_lexer_skip_spaces(&ptr))
		return (0);
	if (ms_is_quote(*ptr))
		ret = ms_lexer_handle_quotes(&start, &end, &ptr, type);
	else
		ret = ms_lexer_handle_normal(&start, &end, &ptr, type);
	if (ret < 0)
		return (-1);
	*token = cool_strsub(start, 0, (ptr - start));
	if (!*token)
		return (-1);
	*cmd = end;
	return (1);
}

t_lex		*ms_command_lex(char *cmd)
{
	t_ttype	type;
	t_lex	*list;
	char	*token;
	int		ret;

	list = NULL;
	while ((ret = ms_lexer_token_get_next(&cmd, &token, &type)) > 0)
	{
		if (!ms_lex_lstadd(&list, token, type))
		{
			ms_lexer_lstdel(&list);
			return (NULL);
		}
	}
	if (ret < 0)
		ms_lexer_lstdel(&list);
	return (list);
}
