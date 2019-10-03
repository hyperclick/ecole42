int	ft_sqrt_up(int a)
{
	int	s;

	s = 1;
	while (s * s < a)
	{
		++s;
	}
	return (s);
}

