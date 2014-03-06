/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcouly <dcouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 15:51:38 by dcouly            #+#    #+#             */
/*   Updated: 2014/03/06 14:01:11 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"
#include <stdlib.h>

t_jobs	*ms_jobs_lstadd(t_context *context, char *var, int state, int pid)
{
	t_jobs	*elem;
	t_jobs	*current;

	if ((elem = (t_jobs *) cool_malloc(sizeof(t_jobs))) == NULL)
		return ((t_jobs *) ms_function_failed("cool_malloc failed", NULL));
	elem->name = ft_strdup(var);
	elem->pid = pid;
	elem->state = (state) ? (BACKGROUND) : (FORGROUND);
	elem->num = context->nb_job;
	context->nb_job++;
	elem->prev = NULL;
	elem->next = NULL;
	if (context->jobs == NULL)
	{
		context->jobs = elem;
		return (elem);
	}
	current = context->jobs;
	while (current->next)
		current = current->next;
	elem->prev = current;
	current->next = elem;
	return (context->jobs);
}

t_jobs	*ms_jobs_lstdelone(t_jobs **current)
{
	t_jobs	*next;
	t_jobs	*prev;

	if (*current)
	{
		next = (*current)->next;
		prev = (*current)->prev;
		if ((*current)->prev)
			((*current)->prev)->next = next;
		if ((*current)->next)
			((*current)->next)->prev = prev;
		cool_free((*current)->name);
		cool_free(*current);
		*current = next;
	}
	return (*current);
}

void	ms_jobs_lstdel(t_context *context)
{
	t_jobs	*current;
	t_jobs	*next;

	current = context->jobs;
	while (current)
	{
		next = current->next;
		cool_free(current->name);
		cool_free(current);
		current = next;
	}
	current = NULL;
}

void	ms_jobs_add_cmd(char *name, t_context *ctx, int pid)
{
	t_jobs	*current;
	char	*str;

	current = ctx->jobs;
	while (current->next)
		current = current->next;
	str = ft_strjoin(current->name, " | ");
	free(current->name);
	current->pid = pid;
	current->name = ft_strjoin(str, name);
	free(str);
}

void	ms_modif_jobs(t_context *ctx)
{
	t_jobs	*current;
	t_jobs	*mem;

	current = ctx->jobs;
	while (current)
	{
		if (current->state == -1)
		{
			if (current->next)
				(current->next)->prev = current->prev;
			if (current->prev)
				(current->prev)->next = current->next;
			if (current->next == NULL && current->prev == NULL)
				ctx->jobs = NULL;
			else if (current->prev == NULL)
				ctx->jobs = ctx->jobs->next;
			cool_free(current->name);
			mem = current;
			current = current->next;
			cool_free(mem);
		}
		else
			current = current->next;
	}
}
