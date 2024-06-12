# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 16:54:15 by dcarenou          #+#    #+#              #
#    Updated: 2024/06/12 06:26:22 by bstablo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= builtins/add.c \
			  builtins/add2.c \
			  builtins/add3.c \
			  builtins/add4.c \
			  builtins/add5.c \
			  builtins/add6.c \
			  builtins/add7.c \
			  builtins/exit.c \
			  builtins/export.c \
			  builtins/export2.c \
			  builtins/ft_cd.c \
			  builtins/ft_echo.c \
			  builtins/ft_print_env.c \
			  builtins/port.c \
			  builtins/pwd.c \
			  builtins/unset.c \
			  exec/exec_utils.c \
			  exec/exec.c \
			  exec/wrongcmd.c \
			  parse/cmd_arg.c \
			  parse/heredoc.c \
			  parse/parsing_utils.c \
			  parse/parsing.c \
			  parse/quotes.c \
			  parse/redirection.c \
			  parse/replace_utils.c \
			  parse/replaceq.c \
			  parse/replacev.c \
			  utils/free.c \
			  utils/ft_utils.c \
			  utils/itoa.c \
			  utils/list.c \
			  utils/list2.c \
			  utils/strtrim.c \
			  utils/utils.c \
			  check_path.c \
			  cp_env.c \
			  errors.c \
			  free.c \
			  ft_utils.c \
			  main.c \
			  signals.c \
			  env.c \
			  exp.c \
			  

GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = minishell

FRONTNAME = MINISHELL

CC = cc

OBJECTS	= ./bin
 
CFLAGS =  -Wall -Werror -Wextra -g #-fsanitize=address

LIB		=	libft.a

LIBINC =	-L/Users?$(USER)/.brew/Cellar/readline/8.1.2/lib/

READLINE_PATH = vendor/readline/

READ	=	libft.a -L$(READLINE_PATH)/lib -lreadline

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: ${NAME}

$(READLINE_PATH):
	sh ./install_readline.sh

readline: $(READLINE_PATH)

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@$(CC) $(CFLAGS) -I$(READLINE_PATH)/include $(HEADER) -c $< -o $(<:.c=.o)
	
${NAME}: ${OBJS}
		@make -C libft
		@mv libft/$(LIB) .
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(LIB)$(GREEN)" has been created\n"$(RESET)
		@$(CC) $(OBJS) $(CFLAGS) $(READ) $(LIB) -o $(NAME)
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(FRONTNAME)$(GREEN)" has been created\n"$(RESET)

clean :
		@${RM} ${OBJS} $(LIB)
		@make clean -C libft
		@printf $(RED)"\r\033[K➜ ["$(FRONTNAME)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
		@printf $(RED)"\r\033[K➜ [LIB] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)

fclean: clean
		@printf $(GREEN)"\r\033[K🗑️  Deleted: "$(WHITE)$(FRONTNAME)$(RED)" has been deleted\n"$(RESET)
		@${RM} ${NAME}
		
re: fclean all

.PHONY: all clean fclean re readline
