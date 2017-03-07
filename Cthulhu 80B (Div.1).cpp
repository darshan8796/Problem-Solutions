#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[105];
vector<int> path;
vector<int> temp;
int cnt = 0;
int vis[105][105] = {0};

void fun(int p, int u, int l)
{
	
	if(u==p && l!=0) 
	{
		path = temp;
		
		//for(auto f:path)cout<<f<<" ";
		//cout<<endl;
		cnt++;
		return;
	}
	for(auto v: adj[u])
	{
		
		if(vis[u][v]==0) 
		{
			vis[u][v]=1;
			vis[v][u]=1;
			temp.push_back(v);
			
			fun(p,v, l+1);
			temp.pop_back();
		}
	}
}
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
	
	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()==0)
		{
			cout<<"NO"<<endl;
			exit(0);
		}
	}
	int st;
	for(int i=1;i<=n;i++)
	{
		memset(vis, 0, sizeof(int)*105*105);
		fun(i, i, 0);
		if(cnt==0) continue;
		else if(cnt==1) st = path.size();
		else if(cnt>st)
		{
			cout<<"NO"<<endl;
			exit(0);
		}
	}
	
	if(cnt==st) cout<<"FHTAGN!"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
