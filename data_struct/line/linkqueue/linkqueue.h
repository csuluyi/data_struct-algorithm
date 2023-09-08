#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;	//定义数据类型为整形

//定义链式队列的节点类型
typedef struct linkqueuenode
{
	datatype data;
	struct linkqueuenode *next; 
} linkqueue_node, *linkqueue_pnode;

//将front和rear指针封装
typedef struct linkqueue{
	linkqueue_pnode front,rear;
}link_queue, *link_pqueue;

void init_linkqueue(link_pqueue *Q);
bool in_linkqueue(datatype data, link_pqueue q);
bool is_empty_linkqueue(link_pqueue q);
bool out_linkqueue(link_pqueue q, datatype *D);
void show_linkqueue(link_pqueue q);

#endif
