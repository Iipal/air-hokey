# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/05/23 20:10:11 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := air-hokey
NPWD := $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO := echo -e
endif
ifeq ($(UNAME_S),Darwin)
	ECHO := echo
endif

CC := g++ -Ofast -flto -pipe
CC_DEBUG := g++ -g
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes/
LIBS := -lSDL2

SRCS := $(abspath $(wildcard srcs/*.cpp))
OBJ := $(SRCS:.cpp=.o)

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

DEL := rm -rf

all: $(NAME)

$(OBJ): %.o: %.cpp
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@
	@$(ECHO) "$(SUCCESS)"

$(NAME): $(OBJ)
	@$(ECHO) -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(IFLAGS) $(LIBS) -o $(NAME)
	@$(ECHO) "[$(INVERT)$(GREEN)✓$(WHITE)]"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del $(NAME)
	@$(ECHO) "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))

debug: set_cc_debug pre
	@$(ECHO) "$(INVERT)$(GREEN)Ready for debug.$(WHITE)"
clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

.PHONY: all fclean clean re
