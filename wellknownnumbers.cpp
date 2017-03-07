#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	//int s, k;
	//cin>>s>>k;
	
	for(int k=2;k<=20;k++)
	{
		long long int dp[100] = {0};
		dp[k] = 1;
		dp[k+1] = 1;
	
		for(int i=k+2;i<=20;i++)
		{
			dp[i] = 2*dp[i-1] - dp[(i-1)-k];
			cout<<pow(2,(i-1)-k)-dp[i]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
