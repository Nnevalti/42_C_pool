#include <stdio.h>
#include <string.h>

char *ft_strcpy();
char *ft_strncpy();
int ft_str_is_alpha();
int ft_str_is_numeric();
int ft_str_is_lowercase();
int ft_str_is_uppercase();
int ft_str_is_printable();

char *ft_strupcase();
char *ft_strlowcase();
char *ft_strcapitalize();
unsigned int ft_strlcpy();
void ft_pustr_non_printable();

int main ()
{

	char test[] = "               ";
	char ouais[]= "ouais";
	char test2[] = "                ";
	char ouais2[]= "ouais";
	printf("%s\n", ft_strlcpy(test, ouais, 3));
	printf("%s", strlcpy(test2, ouais2, 3));

	/*printf("%s\n", ft_strupcase(test));
	printf("%s\n", ft_strlowcase(test));*/
	printf("%s\n", ft_strcapitalize(test));
	printf("%s\n", test); 
}
