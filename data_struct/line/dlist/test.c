#include "dlist.h"

int main(int argc, const char *argv[])
{
	dlistnode *H;	//, *p;
	int pos = 0;

	H = dlist_create();
	dlist_show(H);

	while (1)
	{
		printf("input pos:");
		scanf("%d", &pos);
		dlist_delete(H, pos);
		dlist_show(H);
	}
#if 0	
	while (1)
	{
		printf("input pos:");
		scanf("%d", &pos);
		dlist_insert(H, 100, pos);
		dlist_show(H);
	}
#endif
#if 0
	while (1)
	{
		printf("please input pos(-1 exit):");
		scanf("%d", &pos);
		p = dlist_get(H, pos);

		if (-1 == pos)
		{
			break;
		}
		if (p)
		{
			printf("%d\n", p->data);
		}
	}
#endif
	return 0;
}
