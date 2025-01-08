NAME = philo

SRC_DIR = sources/

SRC =	$(SRC_DIR)main.c\
		$(SRC_DIR)actions.c\
		$(SRC_DIR)cleaners.c\
		$(SRC_DIR)error.c\
		$(SRC_DIR)init.c\
		$(SRC_DIR)routine.c\
		$(SRC_DIR)simulation.c\
		$(SRC_DIR)utils.c

FLAGS = -Wall -Werror -Wextra -g

OBJ_DIR = objects/
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))
OBJ_DIRS = $(sort $(dir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJ_DIRS) $(OBJS)
		@cc $(OBJS) -o $(NAME) > /dev/null
		@echo "\n\033[0;32mLet's get philosophical! Philosophical!\033[0m\n"

$(OBJ_DIRS):
		@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		@cc $(FLAGS) $(LIBFT_INC) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)
		@echo "\n\033[0;31mAll is gone\033[0m\n"

re: fclean all

.PHONY: all clean fclean re libft
