# Name of the final executable (change this to whatever you need)
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Rule to create the library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Default rule to build the library
all: $(NAME)

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
