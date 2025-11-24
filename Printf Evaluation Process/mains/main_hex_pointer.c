#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int ret_ft;
	int ret_printf;
	int x = 42;
	void *ptr = &x;

	printf("=== HEX / POINTER TESTS (x, X, p) ===\n\n");

	// Hex lowercase
	ret_ft = ft_printf("ft_printf: hex lower: %x %x %x\n", 0, 42, 424242);
	ret_printf = printf("printf   : hex lower: %x %x %x\n", 0, 42, 424242);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Hex uppercase
	ret_ft = ft_printf("ft_printf: hex upper: %X %X %X\n", 0, 42, 424242);
	ret_printf = printf("printf   : hex upper: %X %X %X\n", 0, 42, 424242);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Pointer normal
	ret_ft = ft_printf("ft_printf: pointer: %p\n", ptr);
	ret_printf = printf("printf   : pointer: %p\n", ptr);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	// Pointer NULL
	ret_ft = ft_printf("ft_printf: NULL pointer: %p\n", (void *)0);
	ret_printf = printf("printf   : NULL pointer: %p\n", (void *)0);
	printf("ret_ft = %d | ret_printf = %d\n\n", ret_ft, ret_printf);

	return (0);
}
