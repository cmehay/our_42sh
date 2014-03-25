/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_42sh.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 00:08:35 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/26 00:13:23 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_jobs
{
	char			*name;
	int				num;
	int				pid;
	int				state;
	struct s_jobs	*prev;
	struct s_jobs	*next;
}				t_jobs;

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}				t_env;

typedef struct	s_str
{
	char			*str;
	struct s_str	*next;
}				t_str;

typedef struct	s_process
{
	pid_t				pid;
	struct s_process	*next;
}				t_process;

typedef struct	s_cap
{
	char	*str_clear;
	char	*str_key_up;
	char	*str_key_down;
	char	*str_key_left;
	char	*str_key_right;
	char	*str_key_backspace;
	char	*str_cursor_down;
	char	*str_cursor_up;
	char	*str_cursor_left;
	char	*str_cursor_right;
	char	*str_cursor_move;
}				t_cap;

typedef struct	s_term
{
	size_t	nb_columns;
	size_t	nb_lines;
	t_cap	cap;
}				t_term;

typedef struct	s_cmd_char
{
	int					character;
	t_bool				cursor;
	struct s_cmd_char	*prev;
	struct s_cmd_char	*next;
}				t_cmd_char;

typedef struct	s_history
{
	t_cmd_char			*cmd_char;
	struct s_history	*prev;
	struct s_history	*next;
}				t_history;

typedef struct	s_context
{
	char		**environ;
	t_env		*env;
	t_process	*processes;
	t_term		*term;
	t_history	*history;
	int			fd;
	t_jobs		*jobs;
	int			nb_job;
	int			gid;
	int			last_gid;
	int			*fg;
	int			num_fg;
}				t_context;

typedef struct	s_key_func_assoc
{
	uint64_t	key;
	int			(*fptr) (t_context *ctx, t_cmd_char **cmd_char);
}				t_key_func_assoc;

typedef enum	e_ttype
{
	TOK_SEMI_COL,
	TOK_D_PIPE,
	TOK_PIPE,
	TOK_D_AND,
	TOK_AND,
	TOK_D_LT_SIGN,
	TOK_LT_SIGN,
	TOK_D_GT_SIGN,
	TOK_GT_SIGN,
	TOK_WORD,
	TOK_UNKNOWN
}				t_ttype;

typedef struct	s_lex
{
	char			*token;
	t_ttype			type;
	struct s_lex	*prev;
	struct s_lex	*next;
}				t_lex;

typedef enum	e_nodetype
{
	NODE_SEMI_COL,
	NODE_AND,
	NODE_OR,
	NODE_PIPE,
	NODE_COMMAND
}				t_nodetype;

typedef void (*t_cleanup) (void *);

typedef struct	s_node
{
	t_nodetype		type;
	void			*data;
	t_cleanup		cleanup;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef enum	e_iotype
{
	IO_DEFAULT,
	IO_PIPE,
	IO_FILE,
	IO_FILE_APPEND,
	IO_READLINE
}				t_iotype;

typedef enum	e_direction
{
	DIR_NONE,
	DIR_LEFT,
	DIR_RIGHT
}				t_direction;

typedef struct	s_cmdio
{
	t_iotype	type;
	char		*filename;
	t_node		*pipenode;
	int			pipe[2];
}				t_cmdio;

typedef enum	e_pipedir
{
	PIPE_READ = 0,
	PIPE_WRITE = 1
}				t_pipedir;

typedef struct	s_command
{
	char	*name;
	char	**argv;
	t_env	*env_cpy;
	t_cmdio	fdin;
	t_cmdio	fdout;
	t_bool	null_env;
}				t_command;

typedef struct s_vars	t_vars;

struct s_vars
{
	char	*name;
	char	*content;
	t_vars	*next;
};

typedef struct s_glob	t_glob;

struct s_glob
{
	char	*file;
	int		len;
	t_glob	*next;
};

#endif
