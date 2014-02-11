/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:37:25 by sbethoua          #+#    #+#             */
/*   Updated: 2014/01/24 19:46:46 by sbethoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int	ms_is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ms_is_special(char c)
{
	return (c == '<' || c == '&' || c == '|' || c == ';' || c == '>');
}

int	ms_is_quote(char c)
{
	return (c == '"');
}

int	ms_is_acceptable(char c)
{
	return (c && !ms_is_quote(c) && !ms_is_space(c) && !ms_is_special(c));
}
