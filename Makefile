# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 19:39:54 by zdnaya            #+#    #+#              #
#    Updated: 2020/11/24 16:47:05 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=  miniRT

MLX 		    = -lmlx -lm -framework OpenGL -framework AppKit


CFLAGE =  -Wall -Wextra -Werror

SRCS			=  work/main.c\
				   work/error.c\
				   work/first_parsing.c\
				   work/camera.c\
				   work/parsing_RT.c\
				   work/color.c\
				   work/raytracing.c\
				   work/mlx_configue.c\
				   work/vector_1.c\
				   work/vector_2.c\
				   work/vector_3.c\
				   work/image.c\
				   work/check.c\
				   work/phong.c\
				   work/list.c\
				   work/list1.c\
				   work/print_list.c\
				   work/shading.c\
				   work/plan.c\
				   work/sphere.c\
				   work/triangle.c\
				   work/cylindre.c\
				   work/square.c\
				   work/bmp.c\
				   work/translation.c\
				   work/rotation.c\
				   work/button_key.c\
				   work/tools/get_next_line.c\
				   work/tools/get_next_line_utils.c\
				   work/tools/ft_compare_end.c\
				   work/tools/ft_charSplit.c\
				   work/tools/ft_count.c\
				   work/tools/ft_samestr.c\
				   work/tools/ft_stringdel.c\
				   work/tools/ft_free_split.c\
				   work/tools/ft_calloc.c\
				   work/tools/ft_charCount.c\
				   work/tools/ft_lstsize.c\
				   work/tools/ft_list.c\
				   work/tools/add_list_back.c\
				   work/tools/convert_to_double.c\
				   work/tools/my_power.c\
				   work/tools/ft_atoi.c\
				   work/tools/ft_split.c\
				   work/tools/ft_isdigit.c\
				   work/tools/ft_strdup.c\
				   work/tools/ft_strlen.c\

				   
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
				@rm -rf miniRT
				@gcc $(OBJ) -I./include  $(CFLAGE) $(MLX) -o $(NAME)
				@echo "   Made by : \033[1;91mzdnaya\033[m"
				@echo "          _       _______ _____    "
				@echo "         (_)     (_) ___ \_   _|   "
				@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
				@echo " | '_ ' _ \| | '_ \| |    /  | |   "
				@echo " | | | | | | | | | | | |\ \  | |   "
				@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
				@echo "Compilation of miniRT:  \033[1;91mDONE\033[m"


clean:
		@rm -rf $(OBJ)
		@echo "miniRT : Removing Objs"

fclean: clean
		@rm -rf $(NAME)
		@echo "miniRT : Removing miniRT"

re: fclean all