# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/17 16:46:09 by sbethoua          #+#    #+#              #
#    Updated: 2014/03/03 01:19:03 by cmehay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
CC = clang
INCLUDES = -I ./includes/ -I ./libft/includes/
CFLAGS = -g -Wall -Wextra -Werror $(INCLUDES)
LDFLAGS = -L libft/ -lft -L /usr/lib -ltermcap
HEADERFILES = includes/42sh.h
SRCSDIR = ./srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
SRCSFILES = 42sh.c \
			context.c \
			env_list.c \
			str_list.c \
			jobs_list.c \
			var_name_value_get.c \
			prompt.c \
			term_mode.c \
			term_cmd_char_list.c \
			term_history_list.c \
			term_key_lookup.c \
			key_is_arrow_up.c \
			key_is_arrow_down.c \
			key_is_arrow_right.c \
			key_is_arrow_left.c \
			key_is_shift_arrow_up.c \
			key_is_shift_arrow_down.c \
			key_is_shift_arrow_right.c \
			key_is_shift_arrow_left.c \
			key_is_home.c \
			key_is_end.c \
			key_is_ctrl_x.c \
			key_is_ctrl_y.c \
			key_is_ctrl_p.c \
			key_is_ctrl_v.c \
			key_is_ctrl_d.c \
			key_is_backspace.c \
			key_is_return.c \
			term_display.c \
			command_line_get.c \
			command_exec.c \
			command_lexer.c \
			command_search.c \
			lexer_chars.c \
			lexer_handlers.c \
			lexer_list.c \
			ast_build.c \
			ast_command.c \
			ast_command_args.c \
			ast_command_pipe.c \
			ast_command_indir.c \
			ast_operators.c \
			ast_node.c \
			ast_utils.c \
			exec_command.c \
			exec_command_child.c \
			exec_command_prepare.c \
			exec_tree.c \
			exec_pipe.c \
			command_parser.c \
			command_print.c \
			builtin_cd.c \
			builtin_cd_pwd_modify.c \
			builtin_env.c \
			builtin_echo.c \
			builtin_setenv.c \
			builtin_unsetenv.c \
			builtin_exit.c \
			builtin_history.c \
			builtin_jobs.c \
			builtin_bg.c \
			builtin_fg.c \
			builtin_stop.c \
			builtin_point_excl.c \
			builtin_export.c \
			signals.c \
			errors.c \
			vars.c \
			vars_lookup.c \
			builtin_unset.c \
			globing.c \
			globing_dir.c \
			tools.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C libft/

%.o: %.c $(HEADERFILES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C libft/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
