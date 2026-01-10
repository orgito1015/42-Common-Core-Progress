/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleka <oleka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:05:51 by oleka             #+#    #+#             */
/*   Updated: 2025/12/22 13:05:53 by oleka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int	value;
	int	index;
}	t_data;

typedef struct d_list
{
	void			*content;
	struct d_list	*next;
	struct d_list	*prev;
}	t_list;

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_ops;

typedef struct s_three
{
	t_data	*d1;
	t_data	*d2;
	t_data	*d3;
}	t_three;

typedef struct s_ctx
{
	t_ops	ops;
	t_list	*a;
	t_list	*b;
	int		*nums;
	int		size;
	int		i;
	int		bench;
	char	*strategy;
	double	disorder;
}	t_ctx;

/* Operations */
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* Stack utils */
t_list	*stack(void *content);
void	push(t_list **lst, t_list *new);
t_list	*pop(t_list **lst);
void	fill_stack(t_list **stack_a, int *nums, int size);
int		stack_size(t_list *stack_a);
void	free_stack(t_list **stack);

/* Parsing */
int		*parse_single_arg(char *arg, int *size);
int		*parse_args(int argc, char **argv, int *size);
int		check_duplicate(int *arr, int size);
void	free_split(char **parts);
char	**create_array(int ac, char **av);
int		is_valid_int_str(char *s);
int		is_in_int_range(char *s);
int		validate_argv_args(int argc, char **argv);
int		validate_split_args(char **parts);
int		parse_and_validate(int argc, char **argv, t_ctx *ctx);

/* Libft-like helpers */
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Conversions */
long	ft_atol(const char *str);

/* Indexing & Sorting */
int		*index_array(int *nums, int size);
void	assign_indexes_to_stack(t_list *stack, int *indexed);
int		is_sorted(t_list *stack);
void	sort_two(t_list **a, t_ops *ops);
void	sort_three(t_list **a, t_ops *ops);
void	sort_four(t_list **a, t_list **b, t_ops *ops);
void	sort_five(t_list **a, t_list **b, t_ops *ops);
void	push_smallest_to_b(t_list **a, t_list **b, t_ops *ops);
void	radix_sort(t_list **a, t_list **b, int size, t_ops *ops);
void	adaptive_sort(t_list **stack_a, t_list **stack_b,
			double disorder, t_ops *ops);
void	medium_sort(t_list **a, t_list **b, t_ops *ops);
void	selection_sort(t_list **a, t_list **b, t_ops *ops);
void	rotate_b_to_top(t_list **b, int pos, int size, t_ops *ops);
void	simple_sort(t_list **a, t_list **b, t_ops *ops);

/* Disorder */
double	compute_disorder(int *arr, int size);
double	compute_stack_disorder(t_list *stack);

/* Wrappers and benchmark functions */
void	op_sa(t_list **a, t_ops *ops);
void	op_sb(t_list **b, t_ops *ops);
void	op_ss(t_list **a, t_list **b, t_ops *ops);
void	op_pa(t_list **a, t_list **b, t_ops *ops);
void	op_pb(t_list **a, t_list **b, t_ops *ops);
void	op_ra(t_list **a, t_ops *ops);
void	op_rb(t_list **b, t_ops *ops);
void	op_rr(t_list **a, t_list **b, t_ops *ops);
void	op_rra(t_list **a, t_ops *ops);
void	op_rrb(t_list **b, t_ops *ops);
void	op_rrr(t_list **a, t_list **b, t_ops *ops);
void	increment_op(char *op, t_ops *ops);
void	increment_total(char *op, t_ops *ops);
void	print_op(char *op, t_ops *ops);
char	*get_strategy_description(char *strategy_flag, double disorder);
void	display_benchmark(double disorder, char *strategy_name, t_ops *ops);

/* Main helpers */
void	handle_flags(int argc, char **argv, t_ctx *ctx);
#endif
