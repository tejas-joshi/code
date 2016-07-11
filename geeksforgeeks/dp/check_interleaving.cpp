#include<iostream>
#include<string.h>
using namespace std;

bool isInterleaving(char *strA,int lenA,char *strB, int lenB, char *strC, int lenC)
{
	if((lenA+lenB)!=lenC)
		return false;
	
	bool **isIL;
	isIL = new bool*[lenA+1];
	for(int i=0;i<=lenA;i++)
		isIL[i] = new bool[lenB+1];
	
	//memset(isIL,0,(lenA+1)*(lenB+1)*sizeof(bool));			
	
	for(int i=0;i<=lenA;i++)
	{
		for(int j=0;j<=lenB;j++)
		{
			isIL[i][j] = false;
			if(i==0 && j==0)
				isIL[i][j] = true;
			
			else if(i==0 && strB[j-1]==strC[j-1])
				isIL[i][j] = isIL[i][j-1];
			
			else if(j==0 && strA[i-1]==strC[i-1])
				isIL[i][j] = isIL[i-1][j];
			
			else if(strA[i-1]==strC[i+j-1] && strB[j-1]!=strC[i+j-1])
				isIL[i][j] = isIL[i-1][j];
			
			else if(strB[j-1]==strC[i+j-1] && strA[i-1]!=strC[i+j-1])
				isIL[i][j] = isIL[i][j-1];
			
			else if(strA[i-1]==strC[i+j-1] && strB[j-1]==strC[i+j-1])
				isIL[i][j] = (isIL[i-1][j] || isIL[i][j-1]);				
				 
		}
	}

	return isIL[lenA][lenB];
}

int main()
{
	char strA[100],strB[100],strC[100];
	cin >> strA >> strB >> strC;
	cout << isInterleaving(strA,strlen(strA),strB,strlen(strB),strC,strlen(strC)) << endl;
	return 0;	
}
