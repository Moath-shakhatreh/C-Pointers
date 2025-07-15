#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	in_word;
	int	i;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*malloc_word(char *str, char *charset)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		index;

	result = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str && !is_sep(*str, charset))
		{
			result[i] = malloc_word(str, charset);
			i++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	result[i] = 0;
	return (result);
}
