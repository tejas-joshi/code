#include<cstdio>
typedef long long int LL;

LL min(LL a,LL b)
{
	return (a>b)?b:a;
}

int main()
{
    LL N,B,i,j,p,c,noz,k,T;
    scanf("%lld",&T);
    while(T--)
    {
		scanf("%lld %lld",&N,&B);
		noz=N;
		j=B;
		for (i=2;i<=B;i++)
		{
			if (j%i==0)
			{  
				p=0;
				while (j%i==0)
				{
					p++;
					j/=i;
				}
				c=0;
				k=N;
				while (k/i>0)
				{
					c+=k/i;
					k/=i;
				}
				noz=min(noz,c/p);
			}
		}
		printf("%lld\n",noz);
    }
}
