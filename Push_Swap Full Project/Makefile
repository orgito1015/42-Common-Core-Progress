NAME := push_swap

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
RM      := rm -f

INC     := push_swap.h

MAIN := $(firstword $(wildcard push_swap.c main.c))
ifeq ($(MAIN),)
$(error No main file found (expected push_swap.c or main.c). Add it to the project root.)
endif

SRCS := \
	$(MAIN) \
	arguments_parser.c \
	arguments_parser_split.c \
	arguments_validate_input.c \
	push_swap_helpers.c \
	libft_functions_1.c \
	libft_functions_2.c \
	libft_ft_split.c \
	b_stack_core.c \
	b_core_utils.c \
	b_value_indexing.c \
	b_disorder_metrics.c \
	ops_push_and_swap.c \
	ops_rotate.c \
	ops_reverse_rotate.c \
	algorithms_simple_sorting.c \
	algorithms_sorting.c \
	algorithms_special_sort.c \
	algorithms_radix_sorting.c \
	algorithms_chunk_based_sorting.c \
	algorithms_adaptive_sort_strategy.c \
	benchmark_operations_1.c \
	benchmark_operations_2.c \
	benchmark_operations_3.c \
	benchmark_operations_4.c

OBJDIR := obj
OBJS   := $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bench_adaptive: $(NAME)
	shuf -i 0-9999 -n 500 > args.txt ; ./$(NAME) --bench --adaptive $$(cat args.txt) 2> bench.txt | ./checker_os && cat ./bench.txt

bench_simple: $(NAME)
	shuf -i 0-9999 -n 10 > args.txt ; ./$(NAME) --bench --simple $$(cat args.txt) 2> bench.txt | ./checker_os && cat ./bench.txt

bench_medium: $(NAME)
	shuf -i 0-9999 -n 500 > args.txt ; ./$(NAME) --bench --medium $$(cat args.txt) 2> bench.txt | ./checker_os && cat ./bench.txt

bench_complex: $(NAME)
	shuf -i 0-9999 -n 500 > args.txt ; ./$(NAME) --bench --complex $$(cat args.txt) 2> bench.txt | ./checker_os && cat ./bench.txt

.PHONY: all clean fclean re bench_adaptive bench_simple bench_medium bench_complex
