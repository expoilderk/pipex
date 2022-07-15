NAME = pipex
HEADER = pipex.h
LIBFT = libft

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

#SRC_BONUS =

#OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f


$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

#bonus: $(OBJ_BONUS)
#	$(ARCHIVE) $(NAME) $(OBJ) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus
