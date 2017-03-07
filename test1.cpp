#include <iostream>
#include <cstring>

using namespace std;

int count = 0;
int dp[200];

int fun(int n)
{
	if(n<0) return 0;
	if(n==0)
	{
		count++;
		return 1;
	}
	
	if(dp[n] == -1)
	{
		dp[n] = fun(n-2) + fun(n-4);
	}
	else return dp[n];
}
int main()
{
	memset(dp, -1, sizeof(int)*2000);
	int t = fun(10);
	cout<<count<<" "<<t;
	return 0;
}
