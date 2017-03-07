#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, q;
vector<string> adj[40];
int ans = 0;
void dfs(char a, int length)
{
	if(length==n ) 
	{
		ans++;
		return;
	}
	for(auto s: adj[a-'a']) dfs(s[0], length+1);
}
int main()
{
	cin>>n>>q;
	string t1;
	char t2;
	for(int i=0;i<q;i++) 
	{
		cin>>t1>>t2;
		adj[t2-'a'].push_back(t1);
	}
	
	dfs('a',1);	
	cout<<ans;
	return 0;
}
