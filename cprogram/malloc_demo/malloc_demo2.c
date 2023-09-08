#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char * p;
	char s[] = "wel";

	p = s;
	strncpy(p, "welcom", sizeof("welcom"));

	return 0;
}
