//C03/ex03/ft_strncat
#include <unistd.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	char *original_dest = dest;
	int	i = 0;
	int	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < n && src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';

	return original_dest;
}
int	main()
{
	char var1[50] = "hello ";
	char var2[] = "world";
	char *var3 = ft_strncat(var1, var2, 5);

	printf("%s",var3);
	return (0);
}
