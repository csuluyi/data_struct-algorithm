#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (20)

typedef struct student
{
	int no;
	char name[N];
	float score;
}Student;

Student * get_info()
{
	Student * p;

	if(NULL == (p = (Student *)malloc(sizeof(Student))))
	{
		printf("malloc failed\n");
		return NULL;
	}

	p->no = 1;
	strncpy(p->name, "Tom", sizeof("Tom"));
	p->score = 90;

	return p;
}

int main(int argc, const char * argv[])
{
	Student * s;

	if(NULL == (s = get_info()))
	{
		return 0;
	}
	printf("Student info: %d, %s, %f\n", s->no, s->name, s->score);
	free(s);
	s = NULL;

	return 0;
}
