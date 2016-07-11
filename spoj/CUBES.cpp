#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int cube[101];
	int sum,low,high,mid;
	vector< vector<int> > V;

	for(int i=1;i<=100;i++)
		cube[i] = i*i*i;
	
	for(int i=1;i<=98;i++)
		for(int j=i+1;j<=99;j++)
			for(int k=j+1;k<=100;k++)
			{
				sum = cube[i] + cube[j] + cube[k];			
				low = 1;
				high = 100;
				while(high>=low)
				{
					mid = (high+low)/2;
					if(sum==cube[mid])
					{
						vector<int> temp;
						temp.push_back(mid);
						temp.push_back(i);
						temp.push_back(j);
						temp.push_back(k);
						V.push_back(temp);		
						break;	
					}
					else if(sum<cube[mid])
						high = mid - 1;
					else
						low = mid + 1;
				}	
			}

	for(unsigned int i=0; i<V.size()-1; i++)
		for(unsigned int j=0; j<V.size()-i-1;j++)
		{
			vector<int> t1(V[j]);
			vector<int> t2(V[j+1]);
			
			if(t1[0]>t2[0])
				swap(V[j],V[j+1]);
		}
		
	for(unsigned int i=0;i<V.size();i++)
	{
		if(i!=1)
		{
			vector<int>  temp = V[i];
			cout << "Cube = " << temp[0] << ", Triple = (" << temp[1] << "," << temp[2] << "," << temp[3] << ")" << endl;
		}
	}
	return 0;
}
