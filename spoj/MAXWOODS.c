#include<stdio.h>
#include<limits.h>
int main()
{
	int T,m,n,A[201][201],i,j;
	char C[201];
	int block=0,max=INT_MIN;
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
		{
			scanf("%s",C);
			for(j=0;j<n;j++)
			{
				if(i==0 && block)  
					A[i][j] = INT_MIN;
				else
				{
					if(C[j]=='0')
						A[i][j] = 0;
					else if(C[j]=='T')
						A[i][j] = 1;
					else
					{
						A[i][j] = INT_MIN;
						block=1;
					}
				}
			}	
		}		


		max = A[0][0];

		for(i=1;i<n;i++)
		{
			if(A[0][i]>=0)
				A[0][i] = A[0][i] + A[0][i-1];			
			if(A[0][i]>max)
				max = A[0][i];
		}

		for(i=1;i<m;i++)
		{
			if(i%2==0)	// even
			{
				if(A[i][0]>=0)
					A[i][0] = A[i-1][0] + A[i][0];
				if(A[i][0]>max)
					max = A[i][0];
				for(j=1;j<n;j++)
				{
					if(A[i][j]>=0)
						A[i][j] = A[i][j] + ((A[i-1][j]>A[i][j-1])?A[i-1][j]:A[i][j-1]);
					if(A[i][j]>max)
						max = A[i][j];
				}
			}
			else  // odd
			{
				if(A[i][n-1]>=0)
					A[i][n-1] = A[i-1][n-1] + A[i][n-1];
				if(A[i][n-1]>max)
					max = A[i][n-1];
				for(j=n-2;j>=0;j--)
				{
					if(A[i][j]>=0)
						A[i][j] = A[i][j] + ((A[i-1][j]>A[i][j+1])?A[i-1][j]:A[i][j+1]);
					if(A[i][j]>max)
						max = A[i][j];
				}
			}
		}
		
/*
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",A[i][j]);
			printf("\n");
		}
*/

		printf("%d\n",(max>0)?max:0);
		block=0;
		max = INT_MIN;
	}
	return 0;
}
