#include "linklist.h"

linklist list_create()
{
	linklist H;

	if(NULL == (H = (linklist)malloc(sizeof(listnode))))
	{
		printf("malloc failed!\n");
		return NULL;
	}

	H->data = 0;
	H->next = NULL;
	return H;
}

linklist list_create2()
{
	linklist H, r, p;
	int value;

	H = (linklist)malloc(sizeof(listnode));
	if(NULL == H)
	{
		printf("malloc failed.\n");
		return NULL;
	}

	H->data = 0;
	H->next = NULL;
	r = H;

	while(1)
	{
		printf("input a number(-1 exit)");
		scanf("%d", &value);
		if(-1 == value)
		{
			break;
		}

		if(NULL == (p = (linklist)malloc(sizeof(listnode))))
		{
			printf("malloc failed!\n");
			return H;
		}
		p->data = value;
		p->next = NULL;

		r->next = p;	//p节点加入到链表前，r为链表尾部节点
		r = p;		//p节点加入到链表后，p为链表尾部节点，r要更新指向p

	}


	return H;
}

extern linklist list_get(linklist H, int pos)
{
	linklist p = H;
	int i = -1;
	if(pos < 0)
	{
		printf("position is invalid:<0\n");
		return NULL;
	}

	while(p->next && i < pos)
	{
		p = p->next;
		i++;
	}

	if(i == pos)
	{
		return p;
	}
	else
	{
		
		printf("position is invalid: > length\n");
		return NULL;
	}
}

linklist list_locate(linklist H, datatype value)
{
	linklist p = H->next;

	while(p && p->data != value)
	{
		p = p->next;
	}

	return p;
	
}

int list_head_insert(linklist H, datatype value)
{
	linklist p;

	p = (linklist)malloc(sizeof(listnode));
	if(NULL == p)
	{
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = H->next;
	H->next = p;

	return 0;
}

int list_insert(linklist H, int pos, datatype value)
{
	linklist p, q;

	if(0 == pos)
	{
		p = H;
	}
	else
	{
		p = list_get(H, pos -1);
	}

	if(NULL == p)
	{
		printf("para is invalid\n");
	}
	else
	{
		q = (linklist)malloc(sizeof(listnode));
		if(NULL == q)
		{
			printf("malloc failed.\n");
			return -1;
		}

		q->data = value;

		q->next = p->next;
		p->next = q;
		return 0;
	}

	return 0;
}

int list_delete(linklist H, int pos)
{
	linklist p, q;

	if(0 == pos)
	{
		p = H;
	}
	else
	{
		p = list_get(H, pos-1);
	}

	//if(NULL == p || NULL == p->next)
	if(NULL == p || NULL == p->next)
	{
		printf("para invalid.\n");
		return -1;
	}
	else
	{
		q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;
		return 0;
	}
}

int list_order_insert(linklist H, datatype value)
{
	linklist p, q;

	p = (linklist)malloc(sizeof(listnode));
	if(NULL == p)
	{
		printf("malloc failed.\n");
		return -1;
	}

	p->data = value;

	q = H;
	while(q->next && q->next->data < value)
	{
		q = q->next;
	}

	p->next = q->next;
	q->next = p;

	return 0;
}

void list_sort(linklist H)
{
	linklist p, q, r;

	p = H->next;
	H->next = NULL;

	while(p)
	{
		q = p;
		p = p->next;

		r = H;
		while(r->next && r->next->data < q->data)
		{
			r = r->next;
		}

		q->next = r->next;
		r->next = q;
	}
}


void list_reverse(linklist H)
{
	linklist p, q;

	p = H->next;
	H->next = NULL;

	while(p)
	{
		q = p;
		p = p->next;

		q->next = H->next;
		H->next = q;
	}
}

void list_show(linklist H)
{
	while(H->next)
	{
		printf("%d ", H->next->data);
		H = H->next;
	}

	printf("\n");
}
