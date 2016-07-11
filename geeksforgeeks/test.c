#include<stdio.h>
int main()
{
	int i=10;
	int j = ++i*i++;
	printf("%d",j);
	return 0;
}
