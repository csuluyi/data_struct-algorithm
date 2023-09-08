#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


int main(int argc, const char *argv[])
{
	listnode n1;
	linklist p, q;

	n1.data = 10;
	n1.next = NULL;

	p = &n1;

	p->data = 20;

	q = (listnode *)malloc(sizeof(listnode));
	q->data = 30;
	q->next = NULL;

	free(q);
	return 0;
}
