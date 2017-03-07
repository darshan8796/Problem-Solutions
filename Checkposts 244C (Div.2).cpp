/*
	Strongly Connected Components
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
const int MOD = 1e9+7;
long long int am = 1e9 + 2;
int ans = 1;

vector<int> adj[100005];
vector<int> adjR[100005];
int vis[100005] = {0};
stack<int> stk;
int cost[100005];
void dfs(int u)
{
	vis[u] = 1;
	for(auto v: adj[u])
	{
		if(vis[v]==0) dfs(v);
	}
	stk.push(u);
}

void dfs2(int u)
{
	vis[u] = 1;
	
	if(am>cost[u]) ans=1,am = cost[u];
	else if(am==cost[u]) ans++;
	
	for(auto v: adjR[u])
	{
		if(vis[v]==0) dfs2(v);
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>cost[i];
	
	int m;
	cin>>m;
	int t1, t2;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adjR[t2].push_back(t1);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0) dfs(i);
	}
	//cout<<"HERE";
	for(int i=1;i<=100004;i++) vis[i] = 0;
	long long int at = 1;
	long long int sum = 0;
	while(!stk.empty())
	{
		int t = stk.top();
		//	cout<<t<<" ";
		stk.pop();
		ans = 1;
		am = 1e9 + 2;
		
		if(vis[t]==0) 
		{
			dfs2(t);
			at = (at*ans)%(MOD);
			sum += am;
		}
	}
	cout<<sum<<" "<<at;
	
	return 0;
}
