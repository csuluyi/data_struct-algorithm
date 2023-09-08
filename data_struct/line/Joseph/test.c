#include "linklist.h"

int main(int argc, const char *argv[])
{
	linklist H;
	int k = 1, m = 1;

	H = list_create();
	list_show(H);

	list_jose(H, k, m);

	return 0;
}
