#include "seqqueue.h"

/*用循环队列实现如下功能：
 * 用户从键盘输入整数，程序将其入队
 * 用户输入字母，程序将队头元素出队，
 * 并在每一次出队和入队之后打印队列元素*/

int main(int argc, const char *argv[])
{
	seq_pqueue q;	//定义指向顺序队列的指针
	datatype data, t;
	int ret = 0;

	init_seqqueue(&q);	//顺序队列初始化

	while (1)
	{
		printf("请输入一个整数：");
		ret = scanf("%d", &data);
		//输入整数时，入队
		if (1 == ret)
		{
			if (in_seqqueue(data, q))
			{
				show_seqqueue(q);
			}
		}
		//输入字符时，出队
		else
		{
			if (out_seqqueue(q, &t))
			{
				printf("out : %d\n", t);
				show_seqqueue(q);
			}
			//清空输入缓冲区
			while (getchar() != '\n');
		}
		
	}

	return 0;
}
