SRC = main.c				\
		parser.c			\
		error.c				\
		rotate.c			\
		swap.c				\
		push.c				\
		utils.c				\
		args_checker.c		\
		sort.c				\
		distancia.c			\
		posicion.c			\
		

OBJ = $(SRC:%.c=%.o)

#COMPILER
CC = gcc
CFLAGS = -Werror -Wextra -Wall
CFLAGS += -g3 -fsanitize=address

#NAME
NAME = push_swap

#INCLUDES
INC_DIR = Libft
INC = -I $(INC_DIR)

#LINKER
LINK = -LLibft -lft

all: $(NAME)

$(NAME) :$(OBJ)
	make -sC $(INC_DIR)
	$(CC) $(OBJ) $(CFLAGS) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM)  -f $(OBJ)|| true
	make fclean -sC Libft || true

fclean: clean
	$(RM) $(NAME) || true

re: fclean all
