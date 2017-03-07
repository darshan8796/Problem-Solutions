#include <iostream>
#include <cmath>
#include <map>
#include <cinttypes>

using namespace std;

int main()
{
	int n, s, t;
	cin>>n>>s>>t;
	
	int a[100005];
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(s==t)
	{
		cout<<0;
		return 0;
	}
	int c=s;
	int cnt = 0;
	while(1)
	{
		
		 cnt++;
		c = a[c];
		if(c == t)
		{
			cout<<cnt;
			return 0;
		}
		if(c==s)
		{
			cout<<-1;
			return 0;
		}
	}
	
	return 0;
}
