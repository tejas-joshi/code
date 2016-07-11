#include<stdio.h>
typedef long long int LL;

LL temp;
LL power(LL b,LL p,LL M)
{
	if(b==0)
		return 0;
	else if(p==0)
		return 1;
	else
	{
		temp = power(b%M,p/2,M)%M;
		temp = (temp*temp)%M;
		return (p%2)?((temp*b)%M):(temp%M);
	}
}

int main()
{
	int t;
	LL a,r,d,n,M,res,rn2,numr,denm;

	for(scanf("%d",&t);t;t--)
	{
		scanf("%lld %lld %lld",&a,&d,&r);
		scanf("%lld %lld",&n,&M);


		if(n==1)
		{
			printf("%lld\n",a%M);
			continue;
		}	

		if(r==1)
			res = (a%M + (d*(n/2))%M)%M;
		else
		{
			a = a%M;
			d = d%M;			
			rn2 = power(r%M,(n/2)-1,M);

			//printf("rn2 : %lld\n",rn2);

			numr = ((d*((rn2*r-1)%M))%M);
			denm = ((r-1)%M);
			if(numr<0)
				numr = numr+M;
			if(denm<0)
				denm = denm+M;
			res = ((rn2*a)%M + numr/denm)%M;
		}
		
		if(n&1)
			res = (res*r)%M;
		printf("%lld\n",(res>=0)?res:((res+M)%M));
	}
	
	return 0;
}
