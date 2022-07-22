NAME = pipex
NAME_BONUS = pipex_bonus
HEADER = pipex.h pipex_bonus.h 
LIBFT = libft

SRC = main.c pipex.c child_in.c child_out.c \
	push_cmd.c get_cmd.c get_path.c exec_cmd.c \
	parser_cmd.c modifiers.c trim_cmd.c \
	msg_perror.c msg_error.c free_matrix.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = main_bonus.c pipex_bonus.c child_in_bonus.c child_out_bonus.c \
	push_cmd_bonus.c get_cmd_bonus.c get_path_bonus.c exec_cmd_bonus.c \
	child_middle_bonus.c parser_cmd_bonus.c modifiers_bonus.c trim_cmd_bonus.c \
	msg_perror_bonus.c msg_error_bonus.c free_matrix_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) -g $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT)/libft.a -o $(NAME_BONUS)

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
