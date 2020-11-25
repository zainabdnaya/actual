# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 20:55:40 by zdnaya            #+#    #+#              #
#    Updated: 2020/11/25 11:12:08 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= miniRT
SRC_PATH= work_bonus
# SRC_B_PATH= bonus_src
HDR_PATH= headers
# HDR_B_PATH= bonus_headers
OBJ_PATH= obj
OGL_PATH= ./minilibx_opengl_20191021
MMS_PATH= ./minilibx_mms_20200219
SRC_NAME=	main.c\
	error.c\
	first_parsing.c\
	camera.c\
	parsing_RT.c\
	color.c\
	raytracing.c\
	mlx_configue.c\
	vector_1.c\
	vector_2.c\
	vector_3.c\
	image.c\
	check.c\
	phong.c\
	list.c\
	list1.c\
	print_list.c\
	shading.c\
	plan.c\
	sphere.c\
	triangle.c\
	cylindre.c\
	square.c\
	bmp.c\
	translation.c\
	rotation.c\
	button_key.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_compare_end.c\
	ft_charSplit.c\
	ft_count.c\
	ft_samestr.c\
	ft_stringdel.c\
	ft_free_split.c\
	ft_calloc.c\
	ft_charCount.c\
	ft_lstsize.c\
	ft_list.c\
	add_list_back.c\
	convert_to_double.c\
	my_power.c\
	ft_atoi.c\
	ft_split.c\
	ft_isdigit.c\
	ft_strdup.c\
	ft_strlen.c\
	key_press.c\
	rotation_key.c\
# SRC_B_NAME=
HDR_NAME= use.h \
    objects.h \
    get_next_line.h \
    minirt.h \
	
# HDR_B_NAME= calcul_bonus.h\


OBJ_NAME= $(SRC_NAME:.c=.o)
# OBJ_B_NAME= $(SRC_B_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
# OBJ_B= $(addprefix $(OBJ_PATH)/,$(OBJ_B_NAME))
SRC= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
# SRC_B= $(addprefix $(SRC_B_PATH)/,$(SRC_B_NAME))
HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))
# HDR_B= $(addprefix $(HDR_B_PATH)/,$(HDR_B_NAME))

FLAGS=
LMLX_FLAG= -L ./minilibx_opengl_20191021 libmlx.a -L ./minilibx_mms_20200219 libmlx.dylib -framework OpenGL -framework AppKit
IMLX_FLAG= -I /usr/local/include
H_FLAG= -I headers
H_B_FLAG= -I bonus_headers
#***************************************************************************** #
COMP= gcc
all: ogl mms $(NAME) 
$(NAME) :  $(OBJ) 
	@cp ./minilibx_opengl_20191021/libmlx.a .
	@cp ./minilibx_mms_20200219/libmlx.dylib .
	@$(COMP) $(H_FLAG) $(LMLX_FLAG) $(IMLX_FLAG)  $(OBJ) -o $@
	@clear
	@echo "            Made by : \033[1;91mZdnaya\033[m"
	@echo "          _       _______ _____    "
	@echo "         (_)     (_) ___ \_   _|   "
	@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
	@echo " | '_ ' _ \| | '_ \| |    /  | |   "
	@echo " | | | | | | | | | | | |\ \  | |   "
	@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
	@echo "Compilation of $(NAME):  \033[1;32mOK\033[m"
# bonus : lib ogl mms $(LIB_PATH)/$(LIB) $(OBJ_B) $(OGL) $(MMS)
#     @cp ./minilibx_opengl_20191021/libmlx.a .
#     @cp ./minilibx_mms_20200219/libmlx.dylib .
#     @$(COMP) $(H_B_FLAG) $(LLIB_FLAG) $(LMLX_FLAG) $(IMLX_FLAG)  $(OBJ_B) -o $(NAME)
#     @clear
#     @echo "            Made by : \033[1;91mZdnaya\033[m"
#     @echo "          _       _______ _____    "
#     @echo "         (_)     (_) ___ \_   _|   "
#     @echo "  _ __ ___  _ _ __  _| |_/ / | |   "
#     @echo " | '_ ' _ \| | '_ \| |    /  | |   "
#     @echo " | | | | | | | | | | | |\ \  | |   "
#     @echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
#     @echo "Compilation of $(NAME):  \033[1;32mOK\033[m"

ogl:
	@make -sC $(OGL_PATH)
mms:
	@make -sC $(MMS_PATH)

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_FLAG)  -o $@ -c $<
# $(OBJ_PATH)/%.o:  $(SRC_B_PATH)/%.c $(HDR_B) 
#     @mkdir -p $(OBJ_PATH) 
#     @$(COMP) $(FLAGS) $(H_B_FLAG)  -o $@ -c $<
clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33m>> all objects files are deleted.\033[0m" 
fclean: clean
	@rm -rf $(NAME)
	@rm -rf libmlx.a
	@rm -rf libmlx.dylib
	@make clean -sC $(OGL_PATH)
	@make clean -sC $(MMS_PATH)
	@echo "\033[0;31m>> $(NAME) && all obbjects are deleted.\033[0m" 
re : fclean all