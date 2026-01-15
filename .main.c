#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	int c = 3249857;
	char *s = "Random TEST\n";
	void *p = NULL;
	int d = 3249857;
	int i = 3249857;
	unsigned int u = 3249857;
	unsigned int x = 3249857;
	unsigned int X = 3249857;
	printf("-----------------------------------------\n");
	//printf(NULL);
	ft_printf(NULL);
	printf("CharsPrinted: %d\n-----------------------------------------\n", printf("|Hi! This is a printing test. Good luck!\n           Char --> %c\n         String --> %s\nPointer Address --> %p\n        Decimal --> %d\n            Int --> %i\n   Unsigned Dec --> %u\n        Hex Low --> %x\n      Hex Upper --> %X\n%\n%%\n%|\n", c, s, p, d, i, u, x, X) - 2);
	printf("CharsPrinted: %d\n-----------------------------------------\n", ft_printf("|Hi! This is a printing test. Good luck!\n           Char --> %c\n         String --> %s\nPointer Address --> %p\n        Decimal --> %d\n            Int --> %i\n   Unsigned Dec --> %u\n        Hex Low --> %x\n      Hex Upper --> %X\n%\n%%\n%|\n", c, s, p, d, i, u, x, X) - 2);
	return (0);
}
