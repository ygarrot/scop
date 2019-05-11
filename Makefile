# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:06:15 by ygarrot           #+#    #+#              #
#    Updated: 2019/05/11 14:59:21 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all $(NAME) clean fclean re
.SUFFIXES:

NAME = scop

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3
CFLAGS += -fsanitize=address,undefined

SRCDIR = src
OBJDIR = obj
INCDIR =  \
		  includes \
		  libft/includes

SRC = \
	  vertex_list.c \
	  mtl_set_functions.c \
	  mtl_set_functions_1.c \
	  mtl_parser.c \
	  parser.c \
	  main.c

#Colors

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(SRC))))
ALL_OBJ_DIR = $(sort $(dir $(OBJS)))
INCS = $(addprefix -I, $(addsuffix /, $(INCDIR)))

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(INCS) $(LIBFT)
	@echo "$(_CYAN)\nCompiling library $(NAME)... $(_GREEN)DONE$(_END)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(ALL_OBJ_DIR) || true
	@printf "                                                          \r"
	@printf "$(_CYAN)Compiling $@$(_END)\r"
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCS)

clean:
	@echo "$(_RED)Removed objects (.o) files.$(_END)"
	@/bin/rm -rf obj
	make clean -C libft

fclean: clean
	@echo "$(_RED)Removed ($(NAME)).$(_END)"
	@/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean
	make all
