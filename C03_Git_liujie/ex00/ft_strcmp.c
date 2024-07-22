#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if(s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return s1[i] == s2[i];
}
int	main()
{
	char var1[] = "hello";
	char var2[] = "hello";
	printf("Return: %d",ft_strcmp(var1, var2));
	
	return (0);
}

