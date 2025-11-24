#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int ret_ft;
	int ret_printf;

	printf("=== NUMBER TESTS (d, i, u) ===\n\n");

	// Positive number
	ret_ft = ft_printf("ft_printf: d: %d | i: %i\n", 42, 42);
	ret_printf = printf("printf   : d: %d | i: %i\n", 42, 42);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Zero
	ret_ft = ft_printf("ft_printf: zero: %d %i %u\n", 0, 0, 0u);
	ret_printf = printf("printf   : zero: %d %i %u\n", 0, 0, 0u);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Negative numbers
	ret_ft = ft_printf("ft_printf: negative: %d %i\n", -1, -42);
	ret_printf = printf("printf   : negative: %d %i\n", -1, -42);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// INT_MIN and INT_MAX
	ret_ft = ft_printf("ft_printf: INT_MIN: %d | INT_MAX: %d\n", INT_MIN, INT_MAX);
	ret_printf = printf("printf   : INT_MIN: %d | INT_MAX: %d\n", INT_MIN, INT_MAX);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Unsigned range
	ret_ft = ft_printf("ft_printf: unsigned: %u %u %u\n", 0u, 42u, (unsigned int)UINT_MAX);
	ret_printf = printf("printf   : unsigned: %u %u %u\n", 0u, 42u, (unsigned int)UINT_MAX);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	return (0);
}
