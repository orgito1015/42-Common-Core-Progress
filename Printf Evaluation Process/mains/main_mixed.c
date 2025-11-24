#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	int ret_ft;
	int ret_printf;
	char *str = "42 Printf Evaluation";
	int  n = -12345;

	printf("=== MIXED / STRESS TESTS ===\n\n");

	// Mixed line
	ret_ft = ft_printf("ft_printf: [%s] | n=%d | hex=%x | ptr=%p | char=%c | %%\n",
		str, n, n, &n, 'A');
	ret_printf = printf("printf   : [%s] | n=%d | hex=%x | ptr=%p | char=%c | %%\n",
		str, n, n, &n, 'A');
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Long string + multiple formats
	ret_ft = ft_printf(
		"ft_printf: Start-%s-END | %d %i %u %x %X %p %%\n",
		"abcdefghijklmnopqrstuvwxyz",
		INT_MIN, INT_MAX, 4294967295u, 0xdeadbeef, 0xBADC0DE, &str
	);
	ret_printf = printf(
		"printf   : Start-%s-END | %d %i %u %x %X %p %%\n",
		"abcdefghijklmnopqrstuvwxyz",
		INT_MIN, INT_MAX, 4294967295u, 0xdeadbeef, 0xBADC0DE, &str
	);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Edge case: empty string
	ret_ft = ft_printf("ft_printf: empty string: \"%s\"\n", "");
	ret_printf = printf("printf   : empty string: \"%s\"\n", "");
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	return (0);
}
