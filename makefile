# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirch <mhirch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 16:08:26 by mhirch            #+#    #+#              #
#    Updated: 2023/04/18 16:12:32 by mhirch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

FILES = push_swap.c libft.c libft2.c operations_room1.c operations_room2.c \
	sort_utils1.c sort_utils2.c sort_utils3.c sort_utils4.c sort_utils5.c \
	sort_utils6.c sort_utils7.c sort.c split.c store_check.c 

OBJ = $(FILES:.c=.o)

HEADER = push_swap.h 

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	$(CC) $(CFLAGS) $(FILES) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
