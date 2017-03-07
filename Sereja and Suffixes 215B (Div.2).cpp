#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int a[100005];
	for(int i=0;i<n;i++) cin>>a[i];
	
	int check[100005] = {0};
	int dp[100005] = {0};
	dp[n-1] = 1;
	check[a[n-1]] = 1;
	for(int i=n-2;i>=0;i--) 
	{
		if(check[a[i]]==0) check[a[i]]=1, dp[i] = dp[i+1] + 1;
		else dp[i] = dp[i+1];
	}
	
	for(int i=0;i<m;i++)
	{
		int t1;
		cin>>t1;
		cout<<dp[t1-1]<<endl;
	}
	return 0;
}
