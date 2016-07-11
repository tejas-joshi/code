#include<stdio.h>
//#include<stdlib.h>
#include<algorithm>
using namespace std;

/*
int compare(const void *a,const void *b)
{
	return (* (int *)a)-(* (int  *)b);
}
*/

int sum12[10000001];
int sum34[10000001];

int main()
{
	int N,i,j;
	scanf("%d",&N);
	
	int arr[N][4];	

	for(i=0;i<N;i++)
		scanf("%d%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3]);

	int elem=0;		
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			sum12[elem] = arr[i][0]+arr[j][1];	
			sum34[elem] = arr[i][2]+arr[j][3];	
			elem++;
		}

	//qsort(sum12,elem,sizeof(int),compare);
	//qsort(sum34,elem,sizeof(int),compare);
	sort(sum12,sum12+elem);
	sort(sum34,sum34+elem);
	
	int left,right,count12,count34,count=0;
	
	i=0,j=elem-1;
	int sum;
	while(i<elem && j>=0)
	{
		sum = sum12[i]+sum34[j];
		if(sum==0)
		{
			count12=0;
			count34=0;
			left = sum12[i];
			right = sum34[j];

			while(i<elem && sum12[i]==left)
			{
				count12++;
				i++;	
			}

			while(j>=0 && sum34[j]==right)
			{
				count34++;
				j--;	
			}
			count = count + count12*count34;
		}
		else if(sum>0)
			j--;
		else
			i++;
	}	
	printf("%d\n",count);		
	return 0;	
}
