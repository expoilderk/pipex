NAME = pipex
HEADER = pipex.h
LIBFT = libft

SRC = main.c pipex.c child_in.c child_out.c \
	push_cmd.c get_cmd.c get_path.c exec_cmd.c \
	parser_cmd.c modifiers.c trim_cmd.c \
	msg_perror.c msg_error.c free_matrix.c

OBJ = $(SRC:.c=.o)

#SRC_BONUS =

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT)/libft.a -o $(NAME)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
