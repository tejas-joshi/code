#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,A[1001][1001],caseN=0;
	int checkA[4000];
	while(1)
	{
		caseN++;
		scanf("%d",&n);
		if(n==0)
			break;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&A[i][j]);

		if(n==1)
		{
			cout << caseN << ". NO" << endl;
			continue;
		}		

		int digS=1;
		int left=0,right=n-1,up=0,down=n-1;
		int len=n;
		
		bool searched=false;
		for(int x=0;x<=((n-1)/2);x++)
		{
			searched=false;
			int count = 2*len + 2*(len-2);
			int sInd;

			int ind=0;	
			for(int i=left;i<=right;i++,ind++)
			{
				checkA[ind] = A[up][i];
				if(A[up][i]==digS && !searched)
				{
					sInd = ind;
					searched=true;
				}
			}
			
			for(int i=up+1;i<=down;i++,ind++)
			{
				checkA[ind] = A[i][right];
				if(A[i][right]==digS && !searched)
				{
					sInd = ind;
					searched=true;
				}
			}
				
			for(int i=right-1;i>=left;i--,ind++)
			{
				checkA[ind] = A[down][i];
				if(A[down][i]==digS  && !searched)
				{
					sInd = ind;
					searched=true;
				}
			}
		
			for(int i=down-1;i>=up+1;i--,ind++)
			{
				checkA[ind] = A[i][left];
				if(A[i][left]==digS  && !searched)
				{
					sInd = ind;
					searched=true;
				}
			}

				
			if(!searched)
				break;

			int cnt=1,diff;
			int changeR = len-1;
			while(cnt<count)
			{
				int md = (cnt-1)/changeR;
				if(md==0)
					diff=1;
				else if(md==1)
					diff=n;
				else if(md==2)
					diff=-1;
				else
					diff=n*(-1);

				if(checkA[(cnt+count+sInd)%count]!=(checkA[(cnt-1+count+sInd)%count]+diff))
				{
					searched=false;
					break;	
				}	
				cnt++;
			}	
			len = len-2;
			digS = digS+n+1;
			left++;
			right--;
			up++;
			down--;
			
			if(!searched)
				break;
		}
		if(!searched)
			cout << caseN << ". NO" << endl;
		else
			cout << caseN << ". YES" << endl;

	}

	return 0;
}
