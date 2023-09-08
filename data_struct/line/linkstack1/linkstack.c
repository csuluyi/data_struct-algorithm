#include "linkstack.h"

void linkstack_create(linklist *S)
{
	*S = (linklist)malloc(sizeof(listnode));
	if (NULL == (*S))
	{
		printf("malloc failed.\n");
	}
	printf("malloc:%p\n", (*S));

	(*S)->data = 0;
	(*S)->next = NULL;
}

int linkstack_empty(linklist s)
{
	if(NULL == s)
	{
		return 1;
	}
	return (NULL == s->next ? 1 : 0);
}

void linkstack_clear(linklist s)
{
	linklist p;

	printf("clear:");
	p = s->next;
	while (p)
	{
		s->next = p->next;
		printf("%d ", p->data);
		free(p);
		p = s->next;
	}
	puts("");
}

int linkstack_push(linklist s, datatype value)
{
	linklist p;

	p = (linklist)malloc(sizeof(listnode));
	if (NULL == p)
	{
		printf("malloc failed.\n");
		return -1;
	}
	printf("malloc:%p, value = %d\n", p, value);
	
	p->data = value;
	p->next = s->next;
	s->next = p;
	return 0;
}

datatype linkstack_pop(linklist s)
{
	linklist p;
	datatype ret;

	p = s->next;
	s->next = p->next;

	ret = p->data;
	free(p);
	p = NULL;

	return ret;
}

datatype linkstack_top(linklist s)
{
	return (s->next->data);
}

void linkstack_free(linklist s)
{
	linklist p;

	printf("free:\n");
	p = s;
	while (p)
	{
		s = s->next;
		printf("%p, %d\n", p, p->data);
		free(p);
		p = s;
	}

}

