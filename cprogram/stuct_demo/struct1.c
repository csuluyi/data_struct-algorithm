#include <stdio.h>
#include <string.h>
#define N (20)

struct student
{
	int no;
	char name[N];
	float score;
}s3 = {3, "s3", 88}, s4 = {4, "s4", 85};

int main(int argc, const char *argv[])
{
	struct student s1, s2;
	
	s1.no = 1;
	strncpy(s1.name, "s1", sizeof(s1));
	s1.score = 90;

	s1.score = 99;
	s1.name[0] = 'S';
	printf("%d %s %.2f\n",s1.no, s1.name, s1.score);
	
	s2 = s1;
	s2.no = 2;
	printf("%d %s %.2f\n",s2.no, s2.name, s2.score);
	printf("%d %s %.2f\n",s3.no, s3.name, s3.score);
	printf("%d %s %.2f\n",s4.no, s4.name, s4.score);
	return 0;
}
