#include<stdio.h>
int main()
{
	int n,t,i,max_index,count;
	short int A[1000001];

	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%hd",&A[i]);

		max_index=0,count=1;

		for(i=1;i<n;i++)
		{
			if(A[max_index]==A[i])
				count++;
			else if(count>0)
				count--;
			else
			{
				max_index=i;
				count=1;
			}	
		}

		count=0;
		for(i=0;i<n;i++)
			if(A[i]==A[max_index])
				count++;
			
		if(count>(n/2))
			printf("YES %d\n",A[max_index]);
		else
			printf("NO\n");
	}
	
	return 0;
}
