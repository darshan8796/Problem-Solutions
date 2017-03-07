#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
	string s;
	cin>>s;
	
	string ans;
	
	int y=0;
	for(int i=0;i<s.length();i++)
	{
		if(y>1 && s[i]==ans[y-1] && s[i]==ans[y-2]) continue;
		if(y>2 && s[i]==ans[y-1] && ans[y-2]==ans[y-3]) continue;
		
		ans.push_back(s[i]);
		y++;
	}
	
	cout<<ans;
	return 0;
}
