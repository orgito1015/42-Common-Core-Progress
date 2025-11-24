
---

## 3. `Makefile`

```makefile
# **************************************************************************** #
#                               Printf Evaluation                              #
# **************************************************************************** #

NAME_BASIC        = test_basic
NAME_NUMBERS      = test_numbers
NAME_HEX_POINTER  = test_hex_pointer
NAME_MIXED        = test_mixed

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
MAIN_DIR = mains

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I$(SRC_DIR)

all: $(NAME_BASIC) $(NAME_NUMBERS) $(NAME_HEX_POINTER) $(NAME_MIXED)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME_BASIC): $(OBJ_FILES) $(MAIN_DIR)/main_basic.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(NAME_NUMBERS): $(OBJ_FILES) $(MAIN_DIR)/main_numbers.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(NAME_HEX_POINTER): $(OBJ_FILES) $(MAIN_DIR)/main_hex_pointer.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

$(NAME_MIXED): $(OBJ_FILES) $(MAIN_DIR)/main_mixed.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME_BASIC) $(NAME_NUMBERS) $(NAME_HEX_POINTER) $(NAME_MIXED)

re: fclean all

.PHONY: all clean fclean re
