#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret_ft;
	int ret_printf;

	printf("=== BASIC TESTS (chars, strings, percent) ===\n\n");

	// Simple string
	ret_ft = ft_printf("ft_printf: Hello, world!\n");
	ret_printf = printf("printf   : Hello, world!\n");
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Character
	ret_ft = ft_printf("ft_printf: Char test: %c %c %c\n", 'A', '4', '#');
	ret_printf = printf("printf   : Char test: %c %c %c\n", 'A', '4', '#');
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// String
	ret_ft = ft_printf("ft_printf: String test: %s\n", "42 Network");
	ret_printf = printf("printf   : String test: %s\n", "42 Network");
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// NULL string
	ret_ft = ft_printf("ft_printf: NULL string: %s\n", (char *)0);
	ret_printf = printf("printf   : NULL string: %s\n", (char *)0);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Percent
	ret_ft = ft_printf("ft_printf: Percent test: %% %% %%\n");
	ret_printf = printf("printf   : Percent test: %% %% %%\n");
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	return (0);
}
