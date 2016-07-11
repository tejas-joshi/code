#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

typedef long long LL;
struct fruit
{
    LL start,end;
};

int compare(fruit a,fruit b)
{
    if(a.start!=b.start)
		return a.start<b.start;
    else
		return a.end<b.end;
}

LL maxi(LL a,LL b)
{	return (a>b)?a:b;	}
LL mini(LL a,LL b)
{	return (a<b)?a:b;	}

int main()
{
    int T;
    cin >> T;
    LL num=0,dp[1002],bonus,index,cut;
    while(T--)
    {
        int n;
        cin >> n;
        vector<fruit> vecF(n);
        for(int i=0;i<n;i++)
			cin >> vecF[i].start >> vecF[i].end;
        
        sort(vecF.begin(),vecF.end(),compare);
		for(int i=0;i<1002;i++)
			dp[i]=0;

        bonus=0;
        for(int i=0;i<n;i++)
        {
            index=INT_MAX,cut=0;
            for(int j=0;j<=i;j++)
                if(vecF[j].end>=vecF[i].start)
                {
                    index=mini(index,j);
                    cut++;
                }

            for(int j=index;j<=i;j++)
            {
                if(cut>2)
					dp[i+1] = maxi(dp[i+1],dp[j]+cut);
                else
					dp[i+1] = maxi(dp[i+1],dp[j]);
                if(vecF[j].end >= vecF[i].start)
					cut--;
            }

            dp[i+1]=maxi(dp[i+1],dp[i]);
            bonus=maxi(bonus,dp[i+1]);
        }
        cout << "Case #" << ++num << ": " << bonus << endl;
    }
    return 0;
}
