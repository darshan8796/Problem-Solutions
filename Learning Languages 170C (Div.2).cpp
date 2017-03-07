#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

vector<int> v[105];
int dsu[105];

int findP(int u)
{
	while(dsu[u]!=u) u = dsu[u];
	return u;
}

void merge(int i, int j)
{
	int ip = findP(i);
	int jp = findP(j);
	if(ip!=jp)
	{
		dsu[jp] = ip; 
	}
}
int main()
{
	for(int i=0;i<105;i++) dsu[i] = i;
	
	int n, m;
	cin>>n>>m;
	
	int k;
	int t;
	int ans = 0;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d", &k);
		if(k==0) dsu[i+1] = -1,ans++;
		while(k--)
		{
			scanf("%d", &t);
			v[t].push_back(i+1);
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		if(v[i].size()<=1) continue;
		auto it = v[i].begin();
		int q = *it;
		it++;
		for(;it!=v[i].end();it++) merge(q, *it);
	}	
	
	int c = 0;
	for(int i=1;i<=n;i++) if(dsu[i]==i) c++;
	
	c = c==0?c:c-=1;
	cout<<(ans+c);
	return 0;
}
