# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 14:50:47 by katakaha          #+#    #+#              #
#    Updated: 2026/01/09 19:00:34 by katakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror -g

OBJ ?= $(SRC:.c=.o)
BONUS_OBJ ?= $(BONUS_SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@
