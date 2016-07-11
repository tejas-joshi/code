#include<stdio.h>
typedef long long int LL;
LL numCell(LL row,LL col,LL n)
{
	LL s = row+col;
	if(s<=(n+1))
		return ((s-1)*(s-2))/2 + ((s%2)?(row-1):(col-1)) + 1;
	else
	{
		row = (n-row);
		col = (n-col);
		s = row + col;
		return (n*n) - (s*(s+1))/2 - ((s%2)?row:col); 
	}
}

int main()
{
	int i;
	LL N,K,row=1,col=1;
	LL sum=0;
	char move;
	
	scanf("%lld %lld",&N,&K);

	for(i=0;i<K+1;++i)
	{
		move = getchar();
		switch(move)
		{
			case 'U':
				sum = sum + numCell(--row,col,N);
				break;
			case 'D':
				sum = sum + numCell(++row,col,N);
				break;
			case 'L':
				sum = sum + numCell(row,--col,N);
				break;
			case 'R':
				sum = sum + numCell(row,++col,N);
				break;
		}
	}
	printf("%lld\n",sum+1);
	
	return 0;
}
