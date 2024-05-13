# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 13:19:14 by sataskin          #+#    #+#              #
#    Updated: 2024/05/13 11:45:31 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c \
		pwd.c

OBJECTS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

%.o:%.c
	@cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS)
	@make -C ./libft
	@cc -Wall -Wextra -Werror $(OBJECTS) $(LIBFT) -o $(NAME) -lreadline
	@echo shell sisters MINISHELL done

clean:
	@make clean -C ./libft
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

debug:
	@cc -Wall -Wextra -Werror -g3 -fsanitize=address $(OBJECT) $(LIBFT) -o $(NAME)

.PHONY: clean fclean all re
