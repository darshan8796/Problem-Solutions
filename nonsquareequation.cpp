//Right but most probably timeout
#include <iostream>
#include <string>
#include <cstdio>
#include <cinttypes>
using namespace std;

int64_t fun(int64_t a)
{
	string s = to_string(a);
	int64_t ans = 0;
	
	for(int i=0;i<s.length();i++)
	{
		ans += ((char)s[i]) - '0';
	}
	//cout<<s<<" ";
	//cout<<ans<<endl;
	return ans;
}
int main()
{
	int64_t n;
	cin>>n;
	
	for(int64_t i=1;i*i<n;i++)
	{
		if(n%i==0)
		{
			if(fun(i) == (n/i)-i)
			{
			cout<<i<<endl;
			return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
