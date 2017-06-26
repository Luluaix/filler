# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdamoune <pdamoune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 22:40:04 by pdamoune          #+#    #+#              #
#    Updated: 2017/06/26 21:46:08 by pdamoune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pdamoune.filler
SOURCES	=	$(PATHLIB)/libft.a \
			src/main.c \
			src/flr_parser.c \
			src/flr_solver.c \
			src/tools/flr_error.c \
			src/tools/flr_data.c \
			src/parser/flr_get_player.c \
			src/parser/flr_get_map.c \
			src/parser/flr_get_piece.c \
			src/solver/flr_set_pos.c \
			src/solver/flr_test_pos.c \
			src/solver/flr_strat.c
CFLAGS	=	-Wall -Wextra -Werror
NOFLAGS =	-Wno -format
CC		=	gcc
PATHLIB	=	libft
PATHINC	=	include

all: $(NAME)

$(NAME): library
		@$(CC) -o $(NAME) $(SOURCES) $(CFLAGS)

lib:
		@rm -rf libft
		@ln -s ~/Documents/42/projets_42/library libft

library:
		@make -C $(PATHLIB)

clean:
		@rm -rf $(PATHOBJ)
		@make clean -C $(PATHLIB)

fclean: clean
		@rm -f $(NAME)
		make fclean -C $(PATHLIB)

re: fclean all

.PHONY: lib, library, clean, fclean, re, all
