#include <unistd.h>

void	ft_putchar(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}
/*
int	main()
{
	char str[] = "hello my G";
	ft_putchar(str);
}
*/
