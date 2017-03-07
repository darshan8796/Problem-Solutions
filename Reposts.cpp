#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

unordered_map<string, int> mp;
vector<int> adj[205];
int ans = -1;
void dfs(int p, int d)
{
	if(adj[p].empty())
	{
		if(d>ans) ans = d;
		return;
	}
	
	for(int c:adj[p])
	{
		dfs(c,d+1);
	}
}

string toL(string s)
{
	for(int i=0;i<s.length();i++) s[i] = tolower(s[i]);
	return s;
}
int main()
{
	int n;
	cin>>n;
	
	string a, b, c;
	
	int ct = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c>>b;
		a = toL(a);
		b = toL(b);
		if(mp.find(b) == mp.end()) mp[b] = ct++;
		if(mp.find(a) == mp.end()) mp[a] = ct++;
		
		adj[mp[b]].push_back(mp[a]);

	}
	
	dfs(0, 0);
	
	cout<<ans+1;
	return 0;
}
