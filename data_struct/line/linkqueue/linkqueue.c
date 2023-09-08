#include "linkqueue.h"

void init_linkqueue(link_pqueue *Q)
{
	linkqueue_pnode q;

	*Q = (link_pqueue)malloc(sizeof(link_queue));
	if (NULL == (*Q))
	{
		perror("init_linkqueue malloc failed.");
		exit(-1);
	}

	q = (linkqueue_pnode)malloc(sizeof(linkqueue_node));
	q->data = 0;
	q->next = NULL;
	
	(*Q)->front = q;
	(*Q)->rear = q;

	return;
}


//入队,队列是队尾添加数据
bool in_linkqueue(datatype data, link_pqueue q)
{
	linkqueue_pnode p;

	p = (linkqueue_pnode)malloc(sizeof(linkqueue_node));
	//入队
	q->rear->next = p;
	q->rear = p;
	p->data = data;

	return true;
}

bool is_empty_linkqueue(link_pqueue q)
{
	if (q->rear == q->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//出列，队列是队头删除数据
bool out_linkqueue(link_pqueue q, datatype *D)
{
	linkqueue_pnode t;

	//判断队列是否为空
	if (is_empty_linkqueue(q))
	{
		printf("队列已空.\n");
		return false;
	}

	//队列非空，出队
	t = q->front;
	q->front = q->front->next;
	*D = q->front->data;

	free(t);

	return true;
}

void show_linkqueue(link_pqueue q)
{
	linkqueue_pnode p;

	if (is_empty_linkqueue(q))
	{
		return;
	}

	for (p = q->front->next; p != q->rear->next; p = p->next)//
	{
		printf("%d\t", p->data);
	}
	printf("\n");
}
