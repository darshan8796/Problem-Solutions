#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int col[200005];
vector<int> adj[200005];
int vis[200005] = {0};
int tCol[200005] = {0};
int sz = 0;
int mx = -1;
int n, m, k;
void dfs(int u)
{
	vis[u] = 1;
	sz++;
	tCol[col[u]]++;
	if(mx<tCol[col[u]]) mx = tCol[col[u]];
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);
	int t1, t2;
	for(int i=1;i<=n;i++) scanf("%d", &col[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d", &t1);
		scanf("%d", &t2);
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			memset(tCol, 0, sizeof(int)*200005);
			sz = 0;
			mx = -1;
			dfs(i);
			ans +=  sz - mx;
		} 
	}
	
	cout<<ans;
	return 0;
}
