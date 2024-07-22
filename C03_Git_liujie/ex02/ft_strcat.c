//C03/ft_strcat
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char *original_dest = dest;
	int i = 0;

	while(*dest)
	{
		i++;
		dest++;
	}
	while(*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	
	return original_dest;
}

int	main()
{
	char	var[50] = "hello";
	char	var1[] = "world";
	write(1, ft_strcat(var, var1), 50);
	return (0);
}
