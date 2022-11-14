# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 17:04:33 by tobiaslst         #+#    #+#              #
#    Updated: 2022/11/14 11:08:27 by aleveil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			push_swap
LIB				=			libft/libft.a
HEADER			=			/includes/push_swap.h

CFLAGS = -Wall -Werror -Wextra
CC	= 	gcc
LFT = -L libft -lft

SRCS 			=			src/cmd_push.c \
							src/cmd_revrotate.c \
							src/cmd_rotate.c \
							src/cmd_swap.c \
							src/list.c \
							src/parsing.c \
							src/radix.c \
							src/sorted.c \
							src/stack.c \
							src/main.c \
							src/opti.c \
							src/debug.c


OBJS			=			$(patsubst %.c, %.o, $(SRCS))

all : lib $(NAME)

$(NAME):${OBJS} ${INCLUDES} ${LIB} Makefile
		@$(CC)  -fsanitize=address -g3 $(LFT) $(OBJS) -I includes -o $(NAME)

lib:
		make -C ./libft


%.o : %.c $(HEADER)
	$(CC)  -fsanitize=address -g3 $(CFLAGS) -c $< -o $@


clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./libft

fclean : clean
		rm -f $(NAME)
		$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
