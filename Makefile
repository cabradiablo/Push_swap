SRC = main.c		\
		parser.c	\
		ft_error.c	\
		rotate.c	\
		swap.c		\
		push.c		\
		

OBJ = $(SRC:%.c=%.o)

#COMPILER
CC = gcc
CFLAGS = -Werror -Wextra -Wall
CFLAGS += -g3 -fsanitize=address

#NAME
NAME = pushswap

#INCLUDES
INC_DIR = Libft
INC = -I $(INC_DIR) -I inc

#LINKER
LINK = -LLibft -lft

all: $(NAME)

$(NAME) :$(OBJ)
	make -sC $(INC_DIR)
	$(CC) $(OBJ) $(CFLAGS) $(LINK) -o $(NAME)

clean:
	@$(RM)  -f $(OBJ)|| true
	make fclean -sC Libft || true

fclean: clean
	$(RM) $(NAME) || true

re: fclean all