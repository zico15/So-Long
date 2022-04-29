# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/04/25 23:09:20 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 		ft_main.c	\
					./base/engine/ft_engine.c  \
					./base/engine/ft_render.c  \
					./base/engine/ft_scene.c  \
					./base/engine/ft_map.c  \
					./base/engine/ft_collision.c  \
					./base/engine/ft_get_base.c  \
					./base/array/ft_array.c  \
					./base/array_malloc/ft_array_malloc.c  \
					./base/array_malloc/ft_malloc.c  \
					./base/file/ft_file.c  \
					./base/img/ft_sprites.c	\
					./base/img/ft_animation.c	\
					./base/event/ft_events.c \
					./base/object/ft_object.c \
					./base/object/ft_player.c \
					./base/object/ft_enemy.c \
					./base/object/ft_exit.c \
					./base/object/ft_title_map.c \
					./base/object/ft_menu.c

OBJS		= 		$(SRCS:.c=.o)


CC			= 		gcc -fsanitize=address -g
CFLAGS		= 		-Wall -Wextra -Werror
LIB			= 		ar rcs
RM			= 		/bin/rm -f
MILIB		=		-I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
UTILLIB		=		util/libft.a
UTILLIB2	=		util/libftprintf.a
NAME		= 		so_long

INCLUDE		= 		./headers

all			:		$(NAME)


$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(UTILLIB) $(UTILLIB2) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	
n			: 
					norminette

clean		:
					$(RM) $(OBJS)

fclean		:		clean
						$(RM) $(NAME)

re			:		fclean all

m			: 		clean fclean
