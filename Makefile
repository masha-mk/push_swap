NAME = push_swap

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

SRC_FILES = push_swap.c \
	  parse_and_index.c split_numbers.c \
	  swap.c rotate.c rev_rotate.c push.c \
	  tiny_sort.c big_sort.c \
	  utils.c utils_algo.c free.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

GREEN = \033[0;32m
GREEN_BOLD = \033[1;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RESET = \033[0m

all : $(NAME)
	@echo "$(GREEN_BOLD)Compilation reussie : $(NAME)$(RESET)"

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compilation de $< terminée.$(RESET)"

clean:
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN_BOLD)clean: dossiers objets supprimés.$(RESET)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(GREEN_BOLD)fclean: executable supprimé.$(RESET)"
re: fclean all

.PHONY: all clean fclean re