#include <iostream>
#include <vector>
#include <cinttypes>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#include <cstring>
const long long INF = 999999999999999;
using namespace std;
typedef pair<long long, long long> ii;

long long n, m;

vector<pair<long long, long long> > adj[100005];

void dk()
{
	priority_queue<ii, vector<ii>, greater<ii> > q;
	
	vector<long long> dis(n+5,INF);
	vector<long long> parent(n+5, -1);
	long long vis[n+5] = {0};
	
	dis[1] = 0;
	parent[1] = 1;
	
	q.push(make_pair(0,1));
	
	while(!q.empty())
	{
		ii temp = q.top();
		q.pop();
		//if(vis[temp.second]==1) continue;
		
		for(auto s: adj[temp.second])
		{
			
			if(dis[s.first]>dis[temp.second]+s.second)
			{
				dis[s.first]=dis[temp.second]+s.second;
				parent[s.first] = temp.second;
				q.push(make_pair(dis[s.first], s.first ));	
			}
		}
		//vis[temp.second] = 1;
		
	}
	
	if(dis[n] == INF)
	{
		cout<<-1;
		return;
	}
	vector<long long> path;
	long long k=n;
	while(parent[k]!=k)
	{
		path.push_back(k);
		k = parent[k];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	for(auto t:path) cout<<t<<" ";
}
int main()
{
	cin>>n>>m;	
	for(long long i=0;i<m;i++)
	{
		long long t1, t2, t3;
		cin>>t1>>t2>>t3;
		
		adj[t1].push_back(make_pair(t2, t3));
		adj[t2].push_back(make_pair(t1, t3));
	}
	
	dk();
	return 0;
}
