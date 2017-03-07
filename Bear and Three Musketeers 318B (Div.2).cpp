#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> adj[4005];
int adm[4005][4005] = {0};
int main()
{
	int n, m;
	cin>>n>>m;
	
	int t1, t2;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
		adm[t1][t2] = 1;
		adm[t2][t1] = 1;
	}
	
	int ans = 1000000;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			for(int k=j+1;k<adj[i].size();k++)
			{
				if(adm[adj[i][j]][adj[i][k]] == 1)
				{
					//cout<<i<<" "<<adj[i][j]<<" "<<adj[i][k]<<endl;
					int q = (adj[i].size()-2) + (adj[adj[i][j]].size()-2) + (adj[adj[i][k]].size()-2);
					if(q<ans) ans = q;
				}
			}
		}
	}
	
	cout<<(ans==1000000?-1:ans);
	return 0;
}
