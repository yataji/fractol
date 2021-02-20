# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yataji <yataji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 11:57:48 by yataji            #+#    #+#              #
#    Updated: 2021/02/20 17:55:03 by yataji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OBJ  = srcs/burningship.o srcs/julia.o srcs/juliatools.o srcs/key.o\
srcs/main.o srcs/mandelbrot.o srcs/tools.o srcs/zoom.o srcs/treecorns.o srcs/menu.o
FLG  = -Wall -Wextra -Werror
INC  = includes/
INCS = includes/fractol.h


all: $(NAME)

%.o : %.c $(INCS)
	@gcc $(FLG) -o $@ -c $< -I $(INC)
	
$(NAME): $(OBJ) 
	@make  -s -C libft
	@gcc $(FLG) libft/libft.a $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "compilation completed\n"

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)
	@printf "clean terminated\n"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(OBJ) $(NAME)
	@printf "clean all\n"

re: fclean all
