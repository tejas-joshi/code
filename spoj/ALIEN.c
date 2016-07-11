#include<stdio.h>
#include<limits.h>
int main()
{	
	int T,At,Bt,P[100001],distMax=0,sumPpl=INT_MAX,start,end,sum=0,l=0,i,next=0;
	for(scanf("%d",&T);T;T--)
	{
		scanf("%d %d",&At,&Bt);
		for(i=0;i<At;i++)
			scanf("%d",&P[i]);

		start=end=-1;
		next=0;
		while(next<At)
		{
			if((sum+P[next])<=Bt)
			{
				if(start==-1)
					start = end = next;
				sum = sum + P[next];
				end = next;
				next++;
				l++;
				if(l>=distMax)
				{
					if(l!=distMax || (l==distMax && (sum<sumPpl)))
						sumPpl = sum;
					distMax=l;		
				}
			}
			else
			{
				if(start==end)
				{
					start=end=-1;
					if(P[next]>Bt)
						next++;
					sum=0;
					l=0;
				}
				else
				{
					sum = sum - P[start];
					l--;
					start++;
				}
			}			
		}
		sum=0;
		l=0;
		printf("%d %d\n",(sumPpl==INT_MAX)?0:sumPpl,distMax);
		sumPpl=INT_MAX;
		distMax=0;
	}
	return 0;
}
