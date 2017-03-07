#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[26];
string ans;
int vis[26];

bool dfs(int p)
{
	vis[p] = -1;
	
	for(int c : v[p])
	{
		//cout<<(char)(p+'a')<<" "<<(char)(c+'a')<<endl;
		if(vis[c] == -1)  return false;
		if(vis[c]==0 &&  !dfs(c)) return false;
		
	}
	
	vis[p] = 1;
	ans.push_back(p+'a');
	return true;
}

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<26;i++)
	{
		vis[i] = 0;
	}
	
	string s[105];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	
	for(int i=1;i<n;i++)
	{
		string a = s[i-1];
		string b = s[i];
		
		int ia=0;
		int mi = min(a.length(), b.length());
		while(ia!=mi && a[ia] == b[ia] ) ia++;
		
		if(ia==mi && b.length()==mi) 
		{
			cout<<"Impossible"; 
			return 0;
		}
		if(ia==mi && a.length() == mi) continue;
		
		v[a[ia]-'a'].push_back(b[ia]-'a');
	}
	
	for(int i=0;i<26;i++)
	{
	
		if(vis[i] == 0)
		{
			if(!dfs(i))
			{
			
				cout<<"Impossible";
				return 0;
			}
		}
	}
	
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;
	return 0;
}
