# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 18:55:39 by skasmi            #+#    #+#              #
#    Updated: 2023/02/10 02:33:45 by skasmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=  -Wall -Wextra -Werror -Imlx 

NAME=cub3D
NAME2=Parssing/cub3d.h

SRCS=Parssing/cub3d.c \
	Parssing/parssing/pars_rgb/pars_rgb.c \
	Parssing/utils.c \
	Parssing/parssing/pars_rgb/pars_rgb_2.c \
	Parssing/parssing/pars_rgb/utils_rgb.c \
	Parssing/parssing/pars_map/pars_map.c \
	Parssing/parssing/pars_map/pars_map_2.c \
	Parssing/parssing/pars_map/pars_map_3.c \
	Parssing/parssing/pars_rgb/pars_assign_rgb.c \
	Parssing/libft/ft_strlen.c \
	Parssing/libft/ft_split.c \
	Parssing/libft/ft_strtrim.c \
	Parssing/libft/ft_memmove.c \
	Parssing/libft/ft_substr.c \
	Parssing/libft/ft_strdup.c \
	Parssing/libft/ft_strncmp.c \
	Parssing/libft/ft_strnstr.c \
	Parssing/libft/ft_memcpy.c \
	Parssing/libft/ft_memset.c \
	Parssing/libft/ft_strcpy.c \
	Parssing/libft/ft_isdigit.c \
	Parssing/libft/ft_atoi.c \
	Parssing/get_next_line/get_next_line.c \
	Parssing/get_next_line/get_next_utils.c \
	src/init.c \
	src/utils.c \
	src/utils2.c \
	src/utils3.c \
	src/utils4.c \
	src/cube3d.c \
	src/convert.c \
	src/additional.c \
	src/init_utils.c \
	src/raycasting.c \
	src/raycast_utils.c \
	src/rendering/mlx_adds.c
	
	
BOBJCTS=$(BSRCS:%.c=%.o)

OBJCTS=$(SRCS:%.c=%.o)

$(NAME) : $(OBJCTS) $(NAME2)
	$(CC) $(CFLAGS) $(OBJCTS) -L. -lmlx -lX11 -lXext -lm  -o $(NAME)
			
	@echo "\033[31m░█████╗░\033[31m██╗░░░██╗\033[31m██████╗░  \033[32m██████╗░\033[32m██████╗░"
	@echo "\033[31m██╔══██╗\033[31m██║░░░██║\033[31m██╔══██╗  \033[32m╚════██╗\033[32m██╔══██╗"
	@echo "\033[31m██║░░╚═╝\033[31m██║░░░██║\033[31m██████╦╝  \033[32m░█████╔╝\033[32m██║░░██║"
	@echo "\033[31m██║░░██╗\033[31m██║░░░██║\033[31m██╔══██╗  \033[32m░╚═══██╗\033[32m██║░░██║"
	@echo "\033[31m╚█████╔╝\033[31m╚██████╔╝\033[31m██████╦╝  \033[32m██████╔╝\033[32m██████╔╝"
	@echo "\033[31m░╚════╝░\033[31m░╚═════╝░\033[31m╚═════╝░  \033[32m╚═════╝░\033[32m╚═════╝░"
all: $(NAME)
	
clean:	
				rm -f $(OBJCTS) $(BOBJCTS)

fclean: clean
				rm -f $(NAME)

re: fclean all 
