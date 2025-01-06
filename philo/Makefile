NAME = philo

SRC_DIR = sources/

SRC = $(SRC_DIR)main.c\


FLAGS = -Wall -Werror -Wextra -g

OBJ_DIR = objects/
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_DIRS = $(sort $(dir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJ_DIRS) $(OBJS)
		@cc $(OBJS) -o $(NAME) > /dev/null
		@echo "\n\033[0;32mLet's mini!\033[0m\n"

$(OBJ_DIRS):
		@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@cc $(FLAGS) $(LIBFT_INC) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)
		@make -C $(LIBFT_DIR) clean

fclean: clean
		@rm -f $(NAME)
		@echo "\n\033[0;31mAll is gone\033[0m\n"

re: fclean all

.PHONY: all clean fclean re libft
