#include<stdio.h>
#include<string.h>
int main()
{
	int t,l1,l2,i,flag; 

	scanf("%d",&t);
	while(t--)
	{
		flag=1;
		int count[256]={0};
		char s1[105],s2[105];

		scanf("%s",s1);
		scanf("%s",s2);		
		
		l1 = strlen(s1);
		l2 = strlen(s2);

		for(i=0;i<l1;i++)		
			count[(int)s1[i]]++;		
		
		for(i=0;i<l2;i++)
			count[(int)s2[i]]--;
		
		for(i=0;i<256;i++)
			if(count[i])
			{
				flag=0;
				break;
			}
			
		if(flag)	
			printf("YES\n");	
		else
			printf("NO\n");	
	}
	return 0;
}
