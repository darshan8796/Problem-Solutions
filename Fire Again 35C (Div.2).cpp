#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define mp make_pair
vector<int> adj[4000200];
int st[4000200];
int vis[4000200] = {0};
queue<pair<int,int> > q;
void dfs(int l, int t)
{
	vis[l] = 1;
	if(t<st[l]) st[l] = t;
	for(auto v: adj[l]) 
	{
		//cout<<l<<":"<<v<<" ";
		if(vis[v]==0) dfs(v, t+1);
	}
}
int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i!=1) adj[m*(i-1)+j].push_back(m*(i-1-1)+j);
			if(i!=n) adj[m*(i-1)+j].push_back(m*(i-1+1)+j);
			if(j!=1) adj[m*(i-1)+j].push_back(m*(i-1)+j-1);
			if(j!=m) adj[m*(i-1)+j].push_back(m*(i-1)+j+1);
		}
	}
	
	int k;
	cin>>k;
	
	int t1, t2;
	for(int i=1;i<4000200;i++) st[i] = 1e9 + 1;
	for(int i=0;i<k;i++)
	{
		cin>>t1>>t2;
		for(int i=1;i<4000200;i++) vis[i] = 0;
		//dfs(m*(t1-1)+t2, 0);
		q.push(mp(m*(t1-1)+t2, 0));
		while(!q.empty())
		{
			pair<int, int> t = q.front();
			q.pop();
			if(vis[t.first]!=0) continue;
			vis[t.first] = 1;
			if(t.second<st[t.first]) st[t.first] = t.second;
			for(auto v: adj[t.first]) 
			{
				q.push(mp(v, t.second+1));
			}
			
		}
	}
	
	int mix=-1;
	int mi;
	for(int i=1;i<=m*n;i++)
	{
		//cout<<st[i]<<" ";
		
		if(st[i]>mix) mix = st[i], mi=i;
	} 
	//cout<<endl<<mi<<" "<<mix<<"|";
	int x,y;
	if(mi%m==0)
	{
		x=mi/m; 
		y=m;
	} 
	else
	{
		x=(mi/m)+1;
		y=mi%m;
	}
	cout<<x<<" "<<y;
	return 0;
}

	
