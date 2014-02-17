/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbethoua <sbethoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:29:35 by sbethoua          #+#    #+#             */
/*   Updated: 2014/02/17 18:34:26 by dcouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# include <unistd.h>
# include <stdint.h>

# define __UNUSED__ __attribute__((__unused__))

# define KEY_ARROW_UP          0x000000415b1b
# define KEY_ARROW_DOWN        0x000000425b1b
# define KEY_ARROW_RIGHT       0x000000435b1b
# define KEY_ARROW_LEFT        0x000000445b1b
# define KEY_SHIFT_ARROW_UP    0x41323b315b1b
# define KEY_SHIFT_ARROW_DOWN  0x42323b315b1b
# define KEY_SHIFT_ARROW_RIGHT 0x43323b315b1b
# define KEY_SHIFT_ARROW_LEFT  0x44323b315b1b
# define KEY_HOME              0x000000484f1b
# define KEY_END               0x000000464f1b
# define KEY_CTRL_X            0x000000000018
# define KEY_CTRL_Y            0x000000000019
# define KEY_CTRL_P            0x000000000010
# define KEY_CTRL_V            0x000000000016
# define KEY_CTRL_D            0x000000000004
# define KEY_BACKSPACE         0x00000000007f
# define KEY_RETURN            0x00000000000a

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

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
	t_cmdio	fdin;
	t_cmdio	fdout;
}				t_command;

t_context	*ms_context_get(void);
void		ms_context_init(t_context *context);
t_context	*ms_context_fill(t_context *context, char **environ);
void		ms_context_clean(t_context *context);

t_env		*ms_env_lstadd(t_context *context, char *var);
void		ms_env_lstdelone(t_env **current);
void		ms_env_lstdel(t_context *context);
t_env		*ms_env_get(t_context *context);

t_str		*ms_str_lstadd(char *var, t_str **l_str);
void		ms_str_lstdel(t_str **l_str, int fd);

char		*ms_var_name_get(char *var);
char		*ms_var_value_get(char *var);
t_env		*ms_var_ptr_get(t_context *context, char *name);

void		ms_prompt_run(t_context *context);
t_node		*ms_command_parse(t_context *context);

int			ms_builtins_search_exec(t_context *context, char **argv, int outfd);
char		*ms_command_search(t_context *context, char *cmd);

int			ms_builtin_cd(t_context *context, char **argv, int outfd);
int			ms_builtin_cd_pwd_oldpwd_modify(t_context *context, char **old_pwd);
int			ms_builtin_env(t_context *context, char **argv, int outfd);
int			ms_builtin_setenv(t_context *context, char **argv, int outfd);
int			ms_builtin_unsetenv(t_context *context, char **argv, int outfd);
int			ms_builtin_exit(t_context *context, char **argv, int outfd);

void		ms_signal_catch(void);

void		*ms_function_failed(char *msg, void *ret);
int			ms_err_ret(char *msg, int ret);
void		ms_err_display(char *msg);
void		ms_command_not_found(char *command);

int			ms_is_space(char c);
int			ms_is_special(char c);
int			ms_is_quote(char c);
int			ms_is_acceptable(char c);
t_ttype		ms_lexer_stype_match(char c);
t_ttype		ms_lexer_dtype_match(char c);
int			ms_lexer_handle_special(char **start, char **end,
		char **ptr, t_ttype *typ);
int			ms_lexer_handle_normal(char **start,
		char **end, char **ptr, t_ttype *type);
int			ms_lexer_handle_quotes(char **start,
		char **end, char **ptr, t_ttype *type);
t_lex		*ms_command_lex(char *cmd_line);
t_lex		*ms_lex_lstadd(t_lex **list, char *token, t_ttype type);
void		ms_lexer_lstdel(t_lex **list);
void		ms_lexer_lstdelone(t_lex **list, t_lex *item);

t_node		*ms_ast_node_alloc(t_node *parent, t_direction d, t_nodetype type);
void		ms_ast_node_clean(t_node **node);
t_lex		*ms_ast_lexer_split(t_lex *item);
t_lex		*ms_ast_lexer_find(t_lex *lexer, t_ttype type);
size_t		ms_ast_lexer_count(t_lex *lexer);
int			ms_ast_lexer_is_alien(t_lex *lexer);
void		ms_ast_clean(t_node *node);
t_node		*ms_ast_build(t_node *parent, t_lex *lexer, t_direction dir);
t_node		*ms_ast_build_semicol(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir);
t_node		*ms_ast_build_and(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir);
t_node		*ms_ast_build_or(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir);
t_node		*ms_ast_build_pipe(t_lex *llexer, t_lex *item,
		t_node *parent, t_direction dir);
t_node		*ms_ast_build_command(t_lex *lexer, t_node *parent, t_direction d);
void		ms_ast_command_pipe(t_node *node, t_command *cmd);
int			ms_ast_command_indir(t_command *cmd, t_lex **lexer);
int			ms_ast_command_args(t_command *cmd, t_lex *lexer);

int			ms_exec_tree(t_context *context, t_node *astroot);
int			ms_exec_pipe(t_context *content, t_node *node);
int			ms_exec_command(t_context *context, t_node *node);
int			ms_exec_command_infd_get(t_command *cmd);
int			ms_exec_command_outfd_get(t_command *cmd);
int			ms_exec_processes_wait(t_context *context);
void		ms_command_exec_child(t_context *context, t_command *cmd,
		int infd, int outfd);
int			ms_command_process_add(t_context *context, pid_t child);
char		**ms_env_clone(t_env *env);

void		ms_term_mode_raw(t_term *term);
void		ms_term_mode_default(t_term *term);

t_cmd_char	*ms_get_cursor_position(t_cmd_char **cmd_char);
char		*ms_convert_list_to_str(t_cmd_char *cmd_char);
int			ms_command_line_get(t_context *ctx, int fd, char **cmd_line);

int			ms_key_lookup(t_context *ctx, uint64_t key, t_cmd_char **cmd_char);

t_cmd_char	*ms_cmd_char_lstadd(t_cmd_char *cmd_char, char character);
void		ms_cmd_char_lstdelone(t_cmd_char *current);
void		ms_cmd_char_lstdel(t_cmd_char *cmd_char);

t_history	*ms_history_lstadd(t_history *history, t_cmd_char *cmd_char);
void		ms_history_lstdel(t_history *history);

int			ms_putchar(int c);

int			ms_key_is_arrow_up(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_arrow_down(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_arrow_right(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_arrow_left(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_shift_arrow_up(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_shift_arrow_down(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_shift_arrow_right(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_shift_arrow_left(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_home(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_end(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_ctrl_x(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_ctrl_y(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_ctrl_p(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_ctrl_v(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_ctrl_d(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_backspace(t_context *ctx, t_cmd_char **cmd_char);
int			ms_key_is_return(t_context *ctx, char **cmd, t_cmd_char **cmd_char);
/**/

#endif /* !FT_MINISHELL2_H */