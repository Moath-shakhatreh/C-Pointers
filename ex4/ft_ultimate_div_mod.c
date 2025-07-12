void ft_ultimate_div_mod(int *a, int *b)
{
	int ao = *a;

	*a = *a / *b;
	*b = ao % *b;
}
