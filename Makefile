# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:20:27 by jlu               #+#    #+#              #
#    Updated: 2023/11/22 14:34:58 by jlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_print_char.c \
	  ft_print_digit.c \
	  ft_print_str.c \

BSRC = 

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

BOBJECTS = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(BOBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BOBJECTS)

bonus: .bonus

.bonus: $(OBJECTS) $(BOBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BOBJECTS)
	touch .bonus

clean: 
	rm -f $(OBJECTS) $(BOBJECTS) .bonus

fclean: clean
	rm -f $(NAME) 
	
re: fclean all 

.PHONY: all clean fclean re bonus
