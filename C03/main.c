#include <stdio.h>
#include <string.h>

int ft_strcmp();
int ft_strncmp();
char *ft_strcat();
char *ft_strncat();
char *ft_strstr();
unsigned int ft_strlcat();

int main ()
{

	char test[] = "blobfish";
	char testcat[]= "ForTheWin";
	char test2[] = "blobfish";
	char testcat2[]= "ForTheWin";
	char teststr[] = "blobfish";
	char teststr2[]= "ForTheWin";
	
	char testcmp[] = "blobfish";
	char testcmp2[] = "blobfish2";

	/*printf("%d\n", ft_strcmp(testcmp, testcmp2));
	printf("%d\n", strcmp(testcmp, testcmp2));
	
	printf("%d\n", ft_strncmp(testcmp, testcmp2, 9));
	printf("%d\n", strncmp(testcmp, testcmp2, 9));
	
	printf("%s\n", ft_strncat(test, testcat, 1));
	printf("%s\n", strncat(test2, testcat2, 1));
	
	printf("%s\n", ft_strstr(teststr, "blob"));
	printf("%s\n", strstr(teststr, "blob"));
	
	printf("%s\n", strcat(test, testcat));
	printf("%s\n", ft_strcat(test2, testcat2));*/
	
	printf("%d\n", ft_strlcat(test, testcat, 9));
	printf("%lu", strlcat(test2, testcat2, 9));
}
