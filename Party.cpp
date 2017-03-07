#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[2005];
int lh=-1;
void dfs(int c, int height, int prev = -1)
{
	lh = max(lh, height);
	for(auto v: adj[c])
	{
		if(v!=prev) dfs(v, height+1, c);
	}
}
int main()
{
	int n;
	cin>>n;
	
	vector<int> ps;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(t==-1) ps.push_back(i);
		else
		{
			adj[i].push_back(t);
			adj[t].push_back(i);
		}
	}
	
	int ans = -1;
	for(auto t:ps)
	{
		lh = -1;
		dfs(t,1);
		ans = max(ans, lh);
	}
	cout<<ans<<endl;
	return 0;
}
