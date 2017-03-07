#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

vector<int> ad1[405];
vector<int> ad2[405];
int n, m;

typedef pair<int, int> ii;
unordered_set<int> st;

pair<vector<int>, int> dk(vector<int> adj[])
{
	priority_queue<ii, vector<ii>, greater<ii> > q;
	
	vector<int> dis(n+1,INF);
	vector<int> parent(n+1, -1);
	q.push(make_pair(0,1));
	
	dis[1] = 0;
	parent[1] = 1;
	
	while(!q.empty())
	{
		
		ii temp = q.top();
		q.pop();
		
		for(int c:adj[temp.second])
		{
			if(dis[c]>dis[temp.second]+1)
			{
				dis[c] = dis[temp.second]+1;
				parent[c] = temp.second;
				q.push(make_pair(dis[c], c));
			}
		
		}
		
	}
	
	if(dis[n] == INF)
	{
		cout<<-1;
		exit(0);
	}
	vector<int> path;
	int k=n;
	while(parent[k]!=k)
	{
		path.push_back(parent[k]);
		k = parent[k];
	}
	
	reverse(path.begin(), path.end());
	//for(int i:path) cout<<i<<" ";
	
	return make_pair(path, dis[n]);
	/*for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<parent[i]<<" ";
	*/
	
}
int main()
{	
	
	cin>>n>>m;
	
	int t1, t2;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2;
		ad1[t1].push_back(t2);
		ad1[t2].push_back(t1);
	}
	
	for(int i=1;i<=n;i++)
	{
		st.clear();
		for(int c:ad1[i]) st.insert(c);
		
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			if(st.find(j) == st.end()) ad2[i].push_back(j);
		}
	}
	pair<vector<int>, int> q = dk(ad1);
	pair<vector<int>, int> w = dk(ad2);
	/*
	int i=1;
	while(i<q.first.size() && i<w.first.size())
	{
		if(q.first[i] == w.first[i]) cout<<-1; return 0;
		i++;
	}
	*/
	cout<<max(q.second, w.second)<<endl;
	/*for(int i=0;i<q.first.size();i++)
	{
		cout<<q.first[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<w.first.size();i++)
	{
		cout<<w.first[i]<<" ";
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": ";
		for(int c:ad1[i]) cout<<c<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<": ";
		for(int c:ad2[i]) cout<<c<<" ";
		cout<<endl;
	}*/
	return 0;
}
