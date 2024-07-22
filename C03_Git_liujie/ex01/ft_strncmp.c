//C03/Exo01/ft_strncmp
//Jie Liu 18.07.24

int	strncmp(char *s1, char *s2, unsigned int n)
{
	int i = 0;

	while(s1[i] == s2[i] && i < n && s2[i] && s1[i])
	{
		i++;
	}
	
	if(i == n)
	{
		return (0);
	}

	return (s1[i] - s2[i]);
}
