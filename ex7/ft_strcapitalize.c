char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalize;

	i = 0;
	capitalize = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (capitalize)
				str[i] -= 32;
			capitalize = 0;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!capitalize)
				str[i] += 32;
			capitalize = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			capitalize = 0;
		else
			capitalize = 1;
		i++;
	}
	return (str);
}
