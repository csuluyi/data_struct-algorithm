#include<stdio.h>
#include<math.h>

#define N 10
#define _DEBUG_

int get_sum(int n)
{
	int sum =0, i;

	for (i = 1; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

int main(int argc, const char *argv[])
{
	int m = 90, ret;

	printf("argc = %d\n", argc);

	m+= N;
	ret = get_sum(m);
	printf("ret = %d\n", ret);

	return 0;
}
