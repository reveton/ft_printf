# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afomenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 16:44:21 by afomenko          #+#    #+#              #
#    Updated: 2017/04/20 16:52:06 by afomenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
GCC		= gcc
FLAG	= -Wall -Wextra -Werror
SRC		= convert_str.c create_null_struct.c ft_add.c ft_printf.c\
		  get_num.c min.c min2.c num_precision.c parsing.c\
		  print_chr.c print_number.c print_str.c width.c\
		  parsing2.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		mv libft/libft.a ./$(NAME)
		$(GCC) -c $(FLAG) $(SRC) -I ./
		ar rv $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		make clean -C libft/
		rm -rf $(OBJ)

fclean : clean
		make fclean -C libft/
		rm -rf $(NAME)

re : 	fclean all
