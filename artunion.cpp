#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int m, n;
	cin>>m>>n;
	
	int dp[8] = {0};
	int input[50005][7] = {0};
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>input[i][j];
		}
	}
	
	for(int i=0;i<m;i++)
	{
		dp[0] += input[i][0]; 
		for(int j=1;j<n;j++)
		{
			if(dp[j-1]<dp[j])
			{
				dp[j] = dp[j]  + input[i][j] ;
			}
			else
			{
				dp[j] = dp[j-1] + input[i][j] ;
			}
		}
		cout<<dp[n-1]<<" ";
	}
	return 0;
}
