# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yataji <yataji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 11:57:48 by yataji            #+#    #+#              #
#    Updated: 2020/11/14 04:41:19 by yataji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
SRCS= srcs/*.c
FLG= -Wall -Wextra -Werror
INC= includes/
INCS= includes/fractol.h


all: $(NAME)

$(NAME): $(SRCS) $(INCS)
	@make  -s -C libft
	@gcc $(FLG) libft/libft.a $(SRCS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I $(INC)
	@printf "compilation completed\n"

clean:
	@make -C libft/ clean
	@printf "clean terminated\n"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@printf "clean all\n"

re: fclean all
