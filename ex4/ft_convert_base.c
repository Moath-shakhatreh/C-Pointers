#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
char	*ft_putnbr_base(int nbr, char *base);
int		ft_check_base(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(number, base_to));
}
