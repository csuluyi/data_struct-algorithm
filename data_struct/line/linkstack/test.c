#include "linkstack.h"

int main(int argc, const char *argv[])
{
	linklist s = NULL;

	s = linkstack_create();

	linkstack_push(s, 20);
	linkstack_push(s, 30);
	linkstack_push(s, 40);
	linkstack_push(s, 50);
	linkstack_push(s, 60);
	linkstack_push(s, 70);
	linkstack_push(s, 80);
	
	linkstack_free(s);

//	linkstack_clear(s);
	printf("%p\n", s);	//?why print not NULL
	
#if 1
	while (!linkstack_empty(s))
	{
		printf("%d ", linkstack_pop(s));
	}
	puts("");
#endif
}
