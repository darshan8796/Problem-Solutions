#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
char hor[25];
char ver[25];

vector<int> adj[25*25];

int sum = 0;
int vis[25*25] = {0};
void dfs(int u)
{
	vis[u] = 1;
	sum++;
	for(int c:adj[u])
	{
		if(vis[c] == 0) dfs(c);
	}
}
int main()
{
	
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++) cin>>hor[i];
	for(int i=0;i<m;i++) cin>>ver[i];
	
	int x=0;
	int y=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(hor[i] == '>')
			{
				//cout<<"> "<<i<<j<<endl;
				if(j!=m-1) adj[x].push_back(m*y + j+1);
			}
			else if(hor[i] == '<')
			{
				//cout<<"< "<<i<<j<<endl;
				if(j!=0) adj[x].push_back(m*y + j-1);
			}	
			
			if(ver[j] == '^')
			{
				//cout<<"^ "<<i<<j<<endl;
				if(i!=0) adj[x].push_back(m*(y-1) + j);
			}
			else if(ver[j] == 'v')
			{
				//cout<<"v "<<i<<j<<endl;
				if(i!=n-1)adj[x].push_back(m*(y+1) + j);
			}
			
			x++;
		}
		y++;
	}
	
	for(int i=0;i<x;i++)
	{
		memset(vis, 0, sizeof(int)*625);
		sum = 0;
		dfs(i);
		//cout<<sum<<" ";
		if(sum != n*m)
		{
			cout<<"NO";
			return 0;
		}
	}
	
	cout<<"YES";
	
	return 0;
}
