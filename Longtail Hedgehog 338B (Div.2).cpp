#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[100005];

int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int t1, t2;
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}	
	
	long long dp[100005];
	for(int u=1;u<=n;u++) dp[u] = 1;
	for(int u=1;u<=n;u++)
	{
		for(auto v: adj[u]) if(v>u) dp[v] = max(dp[u]+1, dp[v]);		
	}
	
	long long ans = -1;
	for(int u=1;u<=n;u++)
	{
		//cout<<dp[u]<<" ";
		dp[u] *= 1ll*adj[u].size();
		ans = max(ans, dp[u]);
	}
	cout<<ans;
	return 0;
}
