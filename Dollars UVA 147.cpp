#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
int val[] ={0, 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
float dp[12][6005] = {0};
int main()
{
	for(int i=0;i<=11;i++) dp[i][0]=1;
	for(int i=1;i<=11;i++)
		{
			for(int j=1;j<=6000;j++)
			{
				dp[i][j] = dp[i-1][j];	
				if((j)>=val[i]) dp[i][j] += dp[i][(j)-(int)val[i]];
			}
		}
		
	while(1)
	{
		float t;
		cin>>t;
		if(t==0) break;
		//memset(dp, 0, sizeof(int)*12*60005);
		t*=100/5;
				
		cout<<dp[11][(int)t]<<endl;
		//for(int i=0;i<=mx;i++) cout<<a[i]<<" ";
	}	

	return 0;
}
