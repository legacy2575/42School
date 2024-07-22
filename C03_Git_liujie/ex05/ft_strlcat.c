#include <unistd.h>
#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	
	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while(src[j] && (i+j) < size-1)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
    while (src[j] != '\0') { // Continue to count the remaining characters in src.
        j++;
    }
	return (i+j);
}

int	main()
{

	char var[14] = "hello";
	char var2[] = "world";
	
	unsigned int result = ft_strlcat(var, var2, 14);
	printf("%s", var);
	//write(1, &result, 4);

	return (0);
}
