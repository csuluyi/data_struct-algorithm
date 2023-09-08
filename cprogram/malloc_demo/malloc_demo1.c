#include <stdio.h>
#include <stdlib.h>

char * get_string()
{
	char * s;
	s = (char *)malloc(10 * sizeof(char));
	if(NULL == s)
	{
		printf("malloc failed\n");
		return 0;
	}

	printf("input:");
	scanf("%s", s);

	return s;
}

int main(int argc, const char * argv[])
{
	char * p;

	p = get_string();
	printf("%s\n", p);

	free(p);
	p = NULL;

	return 0;
}
