# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:08:26 by mhirch            #+#    #+#              #
#    Updated: 2023/04/20 13:12:32 by mhirch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_NAME = push_swap

CHECKER_NAME = checker

HEADER = push_swap.h

BONUS_HEADER = push_swap_bonus.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

FILES = push_swap.c libft.c libft2.c operations_room1.c operations_room2.c \
	sort_utils1.c sort_utils2.c sort_utils3.c sort_utils4.c sort_utils5.c \
	sort_utils6.c sort_utils7.c sort.c split.c store_check.c 

BONUS_FILES = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	operations_room1_bonus.c operations_room2_bonus.c checker_utils2.c \
	libft.c libft2.c split.c checker.c checker_utils1.c

OBJ = $(FILES:.c=.o)

BONUS_OBJ = $(BONUS_FILES:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(HEADER) $(OBJ)
	$(CC) $(CFLAGS) $(FILES) -o $(PROGRAM_NAME)

bonus : $(BONUS_HEADER) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_FILES) -o $(CHECKER_NAME) 
	
%.o: %.c $(HEADER) $(B_HEADER)
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(PROGRAM_NAME) $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re
