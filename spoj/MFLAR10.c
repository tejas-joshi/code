#include<stdio.h>
int main()
{
	char ch,fCh;

	while(1)
	{
		ch = getchar();
		if(ch=='*')
			break;
		fCh = ch;

		while(1)
		{
			ch = getchar();
			if(ch=='\n')
			{
				printf("Y\n");
				break;
			}
			
			if(ch==' ')
			{
				ch = getchar();
				if(!((ch==fCh) || (ch==(fCh+32)) || (ch==(fCh-32))))
				{
					printf("N\n");

					ch=getchar();
					while(ch!='\n')
						ch = getchar();
					break;
				}
			}
		}	
	}
	
	return 0;
}
