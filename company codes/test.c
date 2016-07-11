#include<stdio.h>
static int n=10;

void print()
{
	static int p;
	printf("static function %d \n",p);
}

int main()
{
	int i,j;
	int A[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			printf("%d\n",A[i][j]);
	print();
	return 0;
}

