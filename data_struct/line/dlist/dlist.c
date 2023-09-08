#include "dlist.h"

dlistnode *dlist_create()
{
	dlistnode *H, *p, *r;
	int n;
	H = (dlistnode *)malloc(sizeof(dlistnode));
	if (NULL == H)
	{
		printf("malloc failed.\n");
		return NULL;
	}

	H->prior = H;
	H->next = H;
	r = H;

	while (1)
	{
		printf("please input(-1 exit):");
		scanf("%d", &n);
		if (-1 == n)
		{
			break;
		}
		p = (dlistnode *)malloc(sizeof(dlistnode));
		if (NULL == p)
		{
			printf("malloc failed.\n");
			return NULL;
		}
		p->data = n;

		p->prior = r;
		p->next = r->next;
		r->next = p;
		H->prior = p;
		r = p;
	}

	return H;
}

void dlist_show(dlistnode *H)
{
	dlistnode *p;

	p = H->next;
	while (p != H)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	puts("");
}


dlistnode *dlist_get(dlistnode *H, int pos)
{
	int i = -1;
	dlistnode *p = H;
	if (pos < 0)
	{
		printf("pos < 0, invalid!\n");
		return NULL;
	}

	while (i < pos)
	{
		p = p->next;
		i++;
		if (p == H)
		{
			printf("pos is valid.\n");
			return NULL;
		}
	}

	return p;
}


int dlist_insert(dlistnode *H, int value, int pos)
{
	dlistnode *p, *q;

	p = dlist_get(H, pos);
	if (NULL == p)
	{
		return -1;
	}

	q = (dlistnode *)malloc(sizeof(dlistnode));
	if (NULL == q)
	{
		printf("malloc failed.\n");
		return -1;
	}
	q->data = value;

	q->prior = p->prior;
	q->next = p;
	p->prior = q;
	q->prior->next = q;

	return 0;
}

int dlist_delete(dlistnode *H, int pos)
{
	dlistnode *p;

	p = dlist_get(H, pos);

	if (NULL == p)
	{
		return -1;
	}

	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p);
	p = NULL;

	return 0;
}
