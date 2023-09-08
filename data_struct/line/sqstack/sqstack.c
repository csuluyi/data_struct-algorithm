#include "sqstack.h"

sqstack *stack_create(int len)
{
	sqstack *s;

	s = (sqstack *)malloc(sizeof(sqstack));
	if (NULL == s)
	{
		printf("malloc fail.\n");
		return NULL;
	}

	s->data = (datatype *)malloc(sizeof(datatype) * s->maxlen);
	if (NULL == s->data)
	{
		
		printf("malloc fail.\n");
		return NULL;
	}

	s->maxlen = len;
	s->top = -1;

	return s;
}

/*
 *ret:1 empty
 * */
int stack_empty(sqstack *s)
{
	return (-1 == s->top) ? 1 : 0;
}

void stack_clear(sqstack *s)
{
	s->top = -1;
}

int stack_full(sqstack *s)
{
	return (s->top == s->maxlen-1) ? 1 : 0;
}

int stack_push(sqstack *s, datatype value)
{
	if (s->top == s->maxlen - 1)
	{
		printf("stack is full.\n");
		return -1;
	}

	s->data[s->top+1] = value;
	s->top++;

	return 0;
}

datatype stack_pop(sqstack *s)
{
	s->top--;

	return s->data[s->top+1];
}

datatype stack_top(sqstack *s)
{
	return s->data[s->top]; 
}


void stack_free(sqstack *s)
{
	free(s->data);
	s->data = NULL;

	free(s);
	s = NULL;

}
