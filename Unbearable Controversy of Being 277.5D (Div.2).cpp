#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> adj[3005];
int adm[3005][3005] = {0};
int main()
{
	int n, m;
	cin>>n>>m;
	
	int t1, t2;
	
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adm[t1][t2] = 1;
	}
	
	int cnt = 0;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cnt = 0;
			if(i == j) continue;
			for(auto v: adj[i])
			{
				if(adm[v][j]==1) cnt++;
			}
			if(cnt>1)
			{
				ans += (cnt*(cnt-1))/2;
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}
