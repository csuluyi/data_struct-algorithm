#ifndef __LINKLIST_H__
#define __LINKLIST_H__

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}listnode, *linklist;

#endif
