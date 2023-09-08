#include "sqstack.h"

int main(int argc, const char *argv[])
{
	sqstack *s;
	int n = 3;

	s = stack_create(n);

	stack_push(s, 10);
	stack_push(s, 20);
	stack_push(s, 30);
	stack_push(s, 40);
	
	while (!stack_empty(s))
	{
		printf("%d ", stack_pop(s));
	}
	puts("");
#if 0
	free(s->data);
	s->data = NULL;
	free(s);
	s = NULL;
#endif
	stack_free(s);
	return 0;
}
