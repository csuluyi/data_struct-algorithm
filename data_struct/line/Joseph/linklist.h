#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *next;
}listnode, *linklist;

extern linklist list_create();
extern void list_show(linklist H);
extern void list_jose(linklist H, int k, int m);

#endif
