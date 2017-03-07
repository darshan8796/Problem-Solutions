/*
	Incorrect. Need to make changes
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 1073741824

using namespace std;

int v[] = {1,2,4,10,20,40};
int dp[7][105] = {0};

int minimumChange(int va)
{
    for(int i = 5; i>-1; i--)
    {
        if(va>= v[i])
        {
            return 1 + minimumChange(va - v[i]);
        }
    }
    return 0;
}


int main()
{
	for(int i=1;i<=100;i++) dp[0][i]=i;
	//cout<<"Here 1";
	for(int i=1;i<6;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(v[i]<=j) dp[i][j] = min(dp[i][j-v[i]]+1, dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	//cout<<"Here 2";
	while(1)
	{
		int a[6];
		int sum=0;
		
		for(int i=0;i<6;i++) 
		{
			cin>>a[i];
			sum += a[i]; 
		}
		//cout<<sum<<endl;
		if(sum==0) break;
		
		int DP[205];
		for(int i=0;i<=200;i++) DP[i] = INF;
		DP[0]=0;
		//cout<<"Here 3";
		for(int k=0;k<6;k++)
		{
			while(a[k])
			{
				for(int i=200-v[k]-1;i>=0;i--)
				{
					if(DP[i]<INF) DP[i+v[k]] = min(DP[i]+1, DP[i+v[k]]);
				}
				a[k]--;
			}
		}
		
		int t;
		cin>>t;
		t*=20;
		
		int ans = INF;
		for(int i=t;i<200;i++)
		{
			 ans = min(ans, minimumChange(i - t) + DP[i]);
		}
		
		printf("%3d\n",ans);
		
	}
	return 0;
}
