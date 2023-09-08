#include "linklist.h"


int main(int argc, const char *argv[])
{
	linklist H;

	H = list_create2();	
	
	list_show(H);
	
	list_sort(H);
	list_show(H);

	return 0;
}
