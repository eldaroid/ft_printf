#include <stdlib.h>

void freemem(char *str)
{
	free(str);
}

int main(void)
{
	char	*str = malloc(5);
	
	//free(str);
	freemem(str);
	return (0);
}