/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:29:35 by sbethoua          #+#    #+#             */
/*   Updated: 2014/03/26 00:13:31 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

#include "structs_42sh.h"

# define __UNUSED__ __attribute__((__unused__))

# define KEY_IS_ARROW_UP 0x000000415b1b
# define KEY_IS_ARROW_DOWN 0x000000425b1b
# define KEY_IS_ARROW_RIGHT 0x000000435b1b
# define KEY_IS_ARROW_LEFT 0x000000445b1b
# define KEY_IS_SHIFT_ARROW_UP 0x41323b315b1b
# define KEY_IS_SHIFT_ARROW_DOWN 0x42323b315b1b
# define KEY_IS_SHIFT_ARROW_RIGHT 0x43323b315b1b
# define KEY_IS_SHIFT_ARROW_LEFT 0x44323b315b1b
# define KEY_IS_HOME 0x000000484f1b
# define KEY_IS_END 0x000000464f1b
# define KEY_IS_CTRL_X 0x000000000018
# define KEY_IS_CTRL_Y 0x000000000019
# define KEY_IS_CTRL_P 0x000000000010
# define KEY_IS_CTRL_V 0x000000000016
# define KEY_IS_CTRL_D 0x000000000004
# define KEY_IS_BACKSPACE 0x00000000007f
# define KEY_IS_RETURN 0x00000000000a

# define STOPPED 0
# define FORGROUND 1
# define BACKGROUND 2

/*
** ast_build.c
*/
t_node		*ms_ast_build(t_node *parent, t_lex *lexer, t_direction dir);

/*
** ast_command.c
*/
t_node		*ms_ast_build_command(t_lex *lexer, t_node *parent, t_direction d);

/*
** ast_command_args.c
*/
int			ms_ast_command_args(t_command *cmd, t_lex *lexer);

/*
** ast_command_indir.c
*/
int			ms_ast_command_indir(t_command *cmd, t_lex **lexer);

/*
** ast_command_pipe.c
*/
void		ms_ast_command_pipe(t_node *node, t_command *cmd);

/*
** ast_node.c
*/
t_node		*ms_ast_node_alloc(t_node *parent, t_direction d, t_nodetype type);
void		ms_ast_node_clean(t_node **node);

/*
** ast_operators.c
*/
t_node		*ms_ast_build_semicol(t_lex *llexer, t_lex *item,
	t_node *parent, t_direction dir);
t_node		*ms_ast_build_and(t_lex *llexer, t_lex *item,
	t_node *parent, t_direction dir);
t_node		*ms_ast_build_or(t_lex *llexer, t_lex *item,
	t_node *parent, t_direction dir);
t_node		*ms_ast_build_pipe(t_lex *llexer, t_lex *item,
	t_node *parent, t_direction dir);

/*
** ast_utils.c
*/
size_t		ms_ast_lexer_count(t_lex *lexer);
int			ms_ast_lexer_is_alien(t_lex *lexer);
void		ms_ast_clean(t_node *node);
t_lex		*ms_ast_lexer_find(t_lex *lexer, t_ttype type);
t_lex		*ms_ast_lexer_split(t_lex *item);

/*
** builtin_gb.c
*/
int			ms_builtin_bg(t_context *context, char **argv, int outfd);

/*
** builtin_cd.c
*/
int			ms_builtin_cd(t_context *context, char **argv, int outfd);

/*
** builtin_cd_pwd_modify.c
*/
int			ms_builtin_cd_pwd_oldpwd_modify(t_context *context, char **old_pwd);

/*
** builtin_echo.c
*/
int			ms_builtin_echo(t_context __UNUSED__ *context, char **argv,
	int outfd);

/*
** builtin_env.c
*/
int			ms_builtin_env(t_context *context, char **argv, int outfd);
t_bool		change_env(t_command *cmd);

/*
** builtin_exit.c
*/
void		ms_kill_all(t_context *context);
int			ms_builtin_exit(t_context *context, char **argv, int outfd);

/*
** builtin_export.c
*/
t_bool		is_a_var_set(char *str);
t_bool		is_a_var(char *str);
char		*find_var(char *var, t_context *context);
int			ms_builtin_setvar(t_context *context, char **argv,
	int __UNUSED__ outfd);
int			ms_builtin_export(t_context *context, char **argv,
	int __UNUSED__ outfd);

/*
** builtin_export_display.c
*/
int			ms_export_display(t_context *context, char **argv, int outfd);

/*
** builtin_fg.c
*/
int			ms_builtin_fg(t_context *context, char **argv, int outfd);

/*
** builtin_history.c
*/
int			ms_builtin_history(t_context *ctx);

/*
** builtin_jobs.c
*/
int			ms_builtin_jobs(t_context *context, int outfd);

/*
** builtin_point_excl.c
*/
int			ms_builtin_point(t_context *context, t_cmd_char **cmd_char);

/*
** builtin_setenv.c
*/
int			ms_builtin_setenv(t_context *context, char **argv, int outfd);

/*
** builtin_stop.c
*/
int			ms_builtin_stop(t_context *context, char **argv, int outfd);

/*
** builtin_unset.c
*/
int			ms_builtin_unset(t_context *context, char **argv,
	int __UNUSED__ outfd);

/*
** builtin_unsetenv.c
*/
int			ms_builtin_unsetenv(t_context *context, char **argv,
	int __UNUSED__ outfd);

/*
** command_exec.c
*/
char		**ms_env_clone(t_env *env);

/*
** command_lexer.c
*/
t_lex		*ms_command_lex(char *cmd_line);

/*
** command_line_get.c
*/
t_cmd_char	*ms_get_cursor_position(t_cmd_char **cmd_char);
char		*ms_convert_list_to_str(t_cmd_char *cmd_char);
int			ms_command_line_get(t_context *ctx, int fd, char **cmd_line);

/*
** command_parser.c
*/
t_node		*ms_command_parse(t_context *context);

/*
** command_print.c
*/
void		ms_clean_line(t_cmd_char **cmd_char, int len, uint64_t nb);
void		ms_print_line(t_cmd_char **cmd_char);

/*
** command_search.c
*/
int			ms_builtins_search_exec2(t_context *context, t_command *cmd,
	int outfd);
char		*ms_command_search(t_env *env_cpy, char *cmd);

/*
** command_search.c
*/
int			ms_builtins_search_exec(t_context *context, t_command *cmd,
	int outfd);

/*
** context.c
*/
t_context	*ms_context_get(void);
void		ms_context_init(t_context *context);
t_context	*ms_context_fill(t_context *context, char **environ);
void		ms_context_clean(t_context *context);

/*
** env_list.c
*/
t_env		*ms_env_lstadd(t_context *context, char *var);
void		ms_env_lstdelone(t_env **current);
void		ms_env_lstdel(t_env *env);
t_env		*ms_env_copy(t_env *env, t_env *prev);
t_env		*ms_env_get(t_context *context);

/*
** errors.c
*/
void		*ms_function_failed(char *msg, void *ret);
int			ms_err_ret(char *msg, int ret);
void		ms_err_display(char *msg);
void		ms_command_not_found(char *command);
int			ms_not_match(char *command);

/*
** exec_command.c
*/
int			ms_command_process_add(t_context *context, pid_t child);
int			ms_exec_command(t_context *context, t_node *node);

/*
** exec_command_child.c
*/
void		ms_command_exec_child(t_context *context, t_command *cmd,
	int infd, int outfd);

/*
** exec_command_fork.c
*/
int			ms_command_exec_normal(t_context *context, t_command *cmd,
	int infd, int outfd);

/*
** exec_command_prepare.c
*/
int			ms_exec_command_outfd_get(t_command *cmd);
int			ms_exec_command_infd_get(t_command *cmd);

/*
** exec_pipe.c
*/
int			ms_exec_pipe(t_context *content, t_node *node);

/*
** exec_tree.c
*/
int			ms_exec_processes_wait(t_context *context);
int			ms_exec_tree(t_context *context, t_node *astroot);

/*
** globing.c
*/
t_bool		matching(char *pattern, char *lookup);
char		*looking_for_match(char *str);
char		*find_match(char *dir, char *pattern);
char		*globing(char *str);
char		*globing_test(char *str);

/*
** globing_dir.c
*/
t_glob		*add_to_match(char *file, char *pattern, t_bool reset);
char		*glob_to_str(t_glob *lst);

/*
** jobs_list.c
*/
t_jobs		*ms_jobs_lstadd(t_context *context, char *var, int state, int pid);
t_jobs		*ms_jobs_lstdelone(t_jobs **current);
void		ms_jobs_lstdel(t_context *context);
void		ms_jobs_add_cmd(char *name, t_context *ctx, int pid);
void		ms_modif_jobs(t_context *ctx);

/*
** key_is_arrow_down.c
*/
int			ms_key_is_arrow_down(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_arrow_left.c
*/
int			ms_key_is_arrow_left(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_arrow_right.c
*/
int			ms_key_is_arrow_right(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_arrow_up.c
*/
void		ms_cmd_char_display(t_cmd_char *cmd_char);
t_cmd_char	*ms_keep_memory(t_cmd_char *cmd_char, int opt);
int			ms_key_is_arrow_up(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_backspace.c
*/
int			ms_key_is_backspace(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_ctrl_d.c
*/
int			ms_key_is_ctrl_d(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_ctrl_p.c
*/
int			ms_key_is_ctrl_p(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_ctrl_v.c
*/
int			ms_key_is_ctrl_v(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_ctrl_x.c
*/
int			ms_key_is_ctrl_x(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_ctrl_y.c
*/
int			ms_key_is_ctrl_y(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_end.c
*/
int			ms_key_is_end(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_home.c
*/
int			ms_key_is_home(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_return.c
*/
int			ms_nb_exec(t_cmd_char **cmd_char);
int			ms_end_comm_part(t_cmd_char *curr);
int			ms_is_background(char last, t_cmd_char *current);
int			ms_key_is_return(t_context *ctx, char **cmd, t_cmd_char **cmd_char);

/*
** key_is_return_fg.c
*/
int			*ms_is_fg_comm(t_cmd_char **cmd_char);

/*
** key_is_shift_arrow_down.c
*/
int			ms_key_is_shift_arrow_down(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_shift_arrow_left.c
*/
int			ms_key_is_shift_arrow_left(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_shift_arrow_right.c
*/
int			ms_key_is_shift_arrow_right(t_context *ctx, t_cmd_char **cmd_char);

/*
** key_is_shift_arrow_up.c
*/
int			ms_key_is_shift_arrow_up(t_context *ctx, t_cmd_char **cmd_char);

/*
** lexer_chars.c
*/
int			ms_is_space(char c);
int			ms_is_special(char c);
int			ms_is_quote(char c);
int			ms_is_acceptable(char c);

/*
** lexer_handlers.c
*/
t_ttype		ms_lexer_stype_match(char c);
t_ttype		ms_lexer_dtype_match(char c);
int			ms_lexer_handle_special(char **start, char **end,
	char **ptr, t_ttype *typ);
int			ms_lexer_handle_normal(char **start,
	char **end, char **ptr, t_ttype *type);
int			ms_lexer_handle_quotes(char **start,
	char **end, char **ptr, t_ttype *type);

/*
** lexer_list.c
*/
t_lex		*ms_lex_lstadd(t_lex **list, char *token, t_ttype type);
void		ms_lexer_lstdel(t_lex **list);
void		ms_lexer_lstdelone(t_lex **list, t_lex *item);

/*
** prompt.c
*/
int			ms_prompt_len(t_context *context);
void		ms_prompt_run(t_context *context);

/*
** signals.c
*/
void		ms_signal_killall(int __UNUSED__ sig);
void		ms_signal_win_resize(int __UNUSED__ sig);
void		ms_signal_exit(int __UNUSED__ sig);
void		ms_signal_stp(int __UNUSED__ sig);
void		ms_nothing(int __UNUSED__ sig);

/*
** signals_catch.c
*/
void		ms_signal_catch(void);

/*
** str_list.c
*/
t_str		*ms_str_lstadd(char *var, t_str **l_str);
void		ms_str_lstdel(t_str **l_str, int fd);

/*
** term_cmd_char_list.c
*/
t_cmd_char	*ms_cmd_char_lstadd(t_cmd_char *cmd_char, char character);
void		ms_cmd_char_lstdelone(t_cmd_char *current);
void		ms_cmd_char_lstdel(t_cmd_char **cmd_char);

/*
** term_display.c
*/
int			ms_putchar(int c);

/*
** term_history_list.c
*/
t_history	*ms_history_lstadd(t_history *history, t_cmd_char *cmd_char);
void		ms_history_lstdel(t_history *history);

/*
** term_key_lookup.c
*/
int			ms_key_lookup(t_context *ctx, uint64_t key, t_cmd_char **cmd_char);

/*
** term_mode.c
*/
void		ms_term_mode_raw(t_term *term);
void		ms_term_mode_default(t_term *term);

/*
** tools.c
*/
char		*sanityze(char *str);
char		*next_dir(char *dir, char *file);

/*
** var_name_value_get.c
*/
char		*ms_var_name_get(char *var);
char		*ms_var_value_get(char *var);
t_env		*ms_var_ptr_get(t_context *context, char *name);
t_env		*ms_env_get_content(t_env *env, char *name);

/*
** vars.c
*/
t_vars		*gimme_vars(void);
void		rm_local_var(char *name);
void		add_local_var(char *name, char *content);
char		*find_local_var(char *name);

/*
** vars_lookup.c
*/
void		looking_for_vars_in_array(char **array, t_context *context);

#endif /* !SH_H */
