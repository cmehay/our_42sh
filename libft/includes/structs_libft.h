/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_libft.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 00:06:06 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/26 00:12:58 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

typedef struct	s_strlen
{
	size_t	s1;
	size_t	s2;
}				t_strlen;

typedef struct	s_alloc_lst
{
	ssize_t				ptr;
	struct s_alloc_lst	*next;
}				t_alloc_lst;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

#endif
