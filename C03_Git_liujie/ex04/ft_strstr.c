#include <unistd.h>

char *ft_strstr(char *str, char *to_find)
{
	char *s1;
	char *s2;

	if(!*to_find)
	{
		return str;
	}
	while(*str)
	{
		s1 = str;
		s2 = to_find;
		while(*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if(!*s2)
			return str;
		str++;
	}
	return NULL;
}

int	main()
{
	char var[11] = " say hello";
	char tofind[] = "helloo";
	write(1, ft_strstr(var, tofind), 5);
	return (0);
}
