#include "linklist.h"

linklist list_create()
{
	linklist H, r, p;
	int n, i;

loop:
	printf("please input n:");
	scanf("%d", &n);
	if (n < 0)
	{
		printf("n > 0.\n");
		goto loop;
	}

	H = (linklist)malloc(sizeof(listnode));
	if (NULL == H)
	{
		printf("malloc failed.\n");
		return NULL;
	}

	H->data = 1;
	H->next = H;
	r = H;

	for (i = 2; i <= n; i++)
	{
		p = (linklist)malloc(sizeof(listnode));
		if (NULL == p)
		{
			printf("malloc failed.\n");
			return NULL;
		}
		p->data = i;
		r->next = p;
		r = p;
	}

	p->next = H;

	return H;
}


void list_jose(linklist H, int k, int m)
{
	int i;
	linklist r, p;

	r = H;

	while (r->next->data != k)
	{
		r = r->next;
	}
	printf("k = %d\n", k);

	while (r->next != r)
	{
		for (i = 0; i < m-1; i++)
		{
			r = r->next;
		}
		p = r->next;
		r->next = p->next;
		printf("%d\n", p->data);
		free(p);
		p = NULL;
	}

	printf("%d\n", r->data);
	free(r);
	r = NULL;

}

void list_show(linklist H)
{
	linklist p = H;

	while (p->next != H)
	{
		printf("%d ", p->data);			
		p = p->next;
	}
	printf("%d\n", p->data);
}
