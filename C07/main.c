char *ft_strdup();
int *ft_range();
int ft_ultimate_range();
char *ft_strjoin();

#include <stdlib.h>

int main ()
{
	//char *s2;
	//char *s1 = "Ceci est un test bidon !";
	//s2 = ft_strdup(s1);
	//printf("%s", s2);
	
	//int *tab;
	//tab = ft_range(10, 15);
	//for (int i = 0; tab[i]; i++)
	//	printf("%d ", tab[i]);
	
	//int **tab;
	//ft_ultimate_range(tab, 10, 15);
	//for (int i = 0; (*tab)[i]; i++)
	//	printf("%d ", (*tab)[i]);

	char **test;
	test = malloc(10000);
	test[0] = "Valentin";
	test[1] = "est";
	test[2] = "un";
	test[3] = "gros";
	test[4] = "debile";
	printf("%s", ft_strjoin(5, test, "\n"));
}
