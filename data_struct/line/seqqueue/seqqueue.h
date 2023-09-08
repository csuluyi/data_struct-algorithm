#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;	//定义数据类型为整形
#define MAXSIZE (10)

typedef struct seqqueue{
	datatype data[MAXSIZE];
	int front,rear;
}seq_queue, *seq_pqueue;

void init_seqqueue(seq_pqueue *Q);
bool is_full_seqqueue(seq_pqueue q);
bool in_seqqueue(datatype data, seq_pqueue q);
bool is_empty_seqqueue(seq_pqueue q);
bool out_seqqueue(seq_pqueue q, datatype *D);
void show_seqqueue(seq_pqueue q);


#endif
