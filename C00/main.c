void ft_print_combn(int n);

int 	main (int argc, char **argv)
{
	printf("%s\n", argv[0]);
	for (int i = 1; i < 10; i++)
	{
		ft_print_combn(i);
		printf("\n\n"); 
	}
	return (0);
}
