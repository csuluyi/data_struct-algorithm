#include "seqqueue.h"

#if 0
seq_pqueue init_seqqueue(void)
{
	seq_pqueue q;

	q = (seq_pqueue)malloc(sizeof(seq_queue));
	if (NULL == q)
	{
		perror("init_seqqueue malloc failed.");
		exit(-1);
	}

	q->front = -1;
	q->rear = -1;

	return q;
}
#endif



void init_seqqueue(seq_pqueue *Q)
{
	*Q = (seq_pqueue)malloc(sizeof(seq_queue));
	if (NULL == (*Q))
	{
		perror("init_seqqueue malloc failed.");
		exit(-1);
	}

	(*Q)->front = MAXSIZE - 1;
	(*Q)->rear = MAXSIZE - 1;

	return;
}

//判断队列是否满。为了解决假溢出创建了环形队列，实际最多存储的数量为MAXSIZE-1
bool is_full_seqqueue(seq_pqueue q)
{
	if (((q->rear+1) % MAXSIZE) == q->front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//入队,队列是队尾添加数据
bool in_seqqueue(datatype data, seq_pqueue q)
{
	//判断队列是否已满
	if (is_full_seqqueue(q))
	{
		printf("队列已满.\n");
		return false;
	}

	//入队
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = data;
	return true;
}

bool is_empty_seqqueue(seq_pqueue q)
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
bool out_seqqueue(seq_pqueue q, datatype *D)
{
	//判断队列是否为空
	if (is_empty_seqqueue(q))
	{
		printf("队列已空.\n");
		return false;
	}

	//出队
	q->front = (q->front+1) % MAXSIZE;
	*D = q->data[q->front];
	return true;
}

void show_seqqueue(seq_pqueue q)
{
	int i = 0;
	if (is_empty_seqqueue(q))
	{
		return;
	}
	//非空时，打印从队头打印数据到队尾
	else
	{
		for (i=((q->front+1)%MAXSIZE); i!=((q->rear+1)%MAXSIZE); i=((i+1)%MAXSIZE))
		{
			printf("%d\t", q->data[i]);
		}
	}
	printf("\n");
}

