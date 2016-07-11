#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
        int t;
        cin >> t;
        double u,v,w,U,V,W,vol,a;
        while(t--)
        {
            cin >> u >> v >> w >> W >> V >> U;
			a=4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)+pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2));
			vol=sqrt(a);
			vol = vol/12;
			printf("%.4lf\n",vol);
		}	
        return 0;
}
