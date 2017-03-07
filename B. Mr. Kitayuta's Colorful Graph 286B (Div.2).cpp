#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

vector< pair<int, int> > adj[105];
int vis[105] = {0};
int ans[105][105] = {0};
void dfs(int p, int u, int col)
{
	vis[u] = 1;
	for(auto v: adj[u])
	{
		if(vis[v.first]==1) continue;	
		if(col==-1)
		{
			ans[p][v.first]++;
			dfs(p, v.first, v.second);
		}
		else if(col == v.second)
		{
			ans[p][v.first]++;
			dfs(p, v.first, v.second);
		}
	}
	vis[u] = 0;
}


int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		adj[t1].push_back(make_pair(t2, t3));
		adj[t2].push_back(make_pair(t1, t3));
	}
	
	for(int i=1;i<=n;i++)
	{
		dfs(i, i,-1);
	}
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++)
	{
		int t1, t2;
		cin>>t1>>t2;
		cout<<ans[t1][t2]<<endl;
	}
	return 0;
}
