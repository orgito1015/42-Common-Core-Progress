# ===========================
# libftprintf — Makefile (sources in project root)
# ===========================

NAME     := libftprintf.a

CC       := cc
CFLAGS   := -Wall -Wextra -Werror
AR       := ar
ARFLAGS  := rcs
RM       := rm -f

OBJ_DIR  := obj

# ---- Explicit sources (no wildcards) ----
SRCS := \
	ft_printf.c \
	ft_print_char.c \
	ft_print_string.c \
	ft_print_number.c \
	ft_print_unsigned.c \
	ft_print_hex.c \
	ft_print_pointer.c \
	ft_utils.c

OBJS := \
	$(OBJ_DIR)/ft_printf.o \
	$(OBJ_DIR)/ft_print_char.o \
	$(OBJ_DIR)/ft_print_string.o \
	$(OBJ_DIR)/ft_print_number.o \
	$(OBJ_DIR)/ft_print_unsigned.o \
	$(OBJ_DIR)/ft_print_hex.o \
	$(OBJ_DIR)/ft_print_pointer.o \
	$(OBJ_DIR)/ft_utils.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# ---- Per-file rules (no pattern dirs) ----
$(OBJ_DIR)/ft_printf.o: ft_printf.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_print_char.o: ft_print_char.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_print_string.o: ft_print_string.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_print_number.o: ft_print_number.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_print_unsigned.o: ft_print_unsigned.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_print_hex.o: ft_print_hex.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_print_pointer.o: ft_print_pointer.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR)/ft_utils.o: ft_utils.c ft_printf.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
