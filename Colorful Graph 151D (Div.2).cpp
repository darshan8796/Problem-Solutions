#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

vector<int> adj[100005];
int c[100005];
set<int> st[100005];
int main()
{
	int n, m;
	cin>>n>>m;
	
	int mi = 100005;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];	
		if(c[i]<mi) mi = c[i];
	}
	
	for(int i=1;i<=m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(auto v: adj[i])
		{
			if(c[i]!=c[v])
			{
				st[c[i]].insert(c[v]);
				//cout<<i<<":"<<v<<" ";
			} 
		}
	}
	
	int ans = -1;
	int anc = -1;
	
	for(int i=1;i<100005;i++)
	{
		if(st[i].size()==0) continue;
		
		//cout<<i<<":"<<st[i].size()<<":"<<anc<<" ";
		int r = st[i].size();
		if(r>anc)
		{
			anc = st[i].size();
			ans = i;
		}
	}
	
	cout<<(ans==-1?mi:ans);
	return 0;
}
