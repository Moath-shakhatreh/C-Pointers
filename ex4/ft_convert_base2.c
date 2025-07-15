#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base_index(char c, char *base)
{
	int	i = 0;

	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	base_len;

	result = 0;
	sign = 1;
	base_len = ft_strlen(base);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_base_index(*str, base) != -1)
	{
		result = result * base_len + ft_base_index(*str, base);
		str++;
	}
	return (result * sign);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char	*result;
	int		base_len;
	int		tmp;
	int		len;
	long	nb;

	base_len = ft_strlen(base);
	nb = nbr;
	len = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? -nb : nb;
	tmp = nb;
	while (tmp > 0 && ++len)
		tmp /= base_len;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
		result[0] = base[0];
	nb = (nbr < 0) ? -((long)nbr) : nbr;
	while (len-- > 0 && nb > 0)
	{
		result[len] = base[nb % base_len];
		nb /= base_len;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}
