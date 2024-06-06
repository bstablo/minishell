# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bstablo <bstablo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 16:54:15 by dcarenou          #+#    #+#              #
#    Updated: 2024/06/06 12:59:09 by bstablo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	
				built-in/ft_cd.c \
				built-in/ft_echo.c \
				built-in/ft_print_env.c \
				built-in/pwd.c \
				exec/exec_utils.c \
				exec/exec.c \
				parse/cmd_arg.c \
				parse/heredoc.c \
				parse/parsing_utils.c \
				parse/parsing.c \
				parse/quotes.c \
				parse/redirection.c \
				parse/replace_utils.c \
				parse/replaceq.c \
				parse/replacev.c \
				utils/utils.c \
				utils/free.c \
				utils/utils2.c \
				utils/srtrim.c \
				utils/list.c \
				utils/list2.c \
				utils/itoa.c \
				check_path.c \
				errors.c \
				free.c \
				signals.c \
				cp_env.c 

OBJS		= $(SRCS:.c=.o)

CC			= cc

CFLAGS		=

LIBFT 		= libft/libft.a

RM			= rm -rf

NAME		= minishell

RED			=	\033[1;31m
GRE			=	\033[1;32m
GRA			=	\033[37m
BLU			=	\033[34m
EOC			=	\033[0m
NNE			=	\033[A\033[0m

#rules
all : $(NAME)

%.o : %.c
	@echo "$(GRE)Compiling : $<                                                   $(GRA)$(NNE)"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJS) $(LIBFT)
	@echo "$(GRE)Compilation of Minishell is finished. $(GRA)"
	@$(CC) $(CFLAGS) $(MINILIB) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@make -C libft/

clean :
	@echo "$(RED)Cleaning of Minishell is finished."
	@$(RM) $(OBJS)
	@make clean -C libft/

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re