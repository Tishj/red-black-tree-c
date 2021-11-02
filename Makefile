# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tbruinem <tbruinem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/19 18:02:35 by tbruinem      #+#    #+#                  #
#    Updated: 2021/11/02 21:02:44 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =	libbst.a

CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG),1)
	CFLAGS += -g -fsanitize=address
endif

SRC_DIR =	./src/
OBJ_DIR =	./obj/

SRC =	util/util_atoi.c \
		util/util_strlen.c \
		util/util_bzero.c \
		util/util_strdup.c \
		util/util_memcpy.c \
		util/util_memcmp.c \
		util/util_memdup.c \
		util/util_strncmp.c \
		util/util_strnlen.c \
		util/util_strncpy.c \
		util/util_swap.c \
		node_delete.c \
		node_lowest.c \
		node_highest.c \
		node_next.c \
		node_prev.c \
		node_find.c \
		node_new.c \
		rbtree_init.c \
		rbtree_insert.c \
		rbtree_assign.c \
		rbtree_find.c \
		rbtree_delete.c \
		rbtree_clear.c

OBJ :=	$(SRC:%.c=$(OBJ_DIR)%.o)
SRC :=	$(SRC:%.c=$(SRC_DIR)%.c)

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I ./incl -c $^ -o $@

$(NAME): $(OBJ)
	ar -rcs $@ $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
