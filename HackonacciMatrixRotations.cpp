#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	printf("HERE"); 
	int n;
	//cin>>n>>q;
	n = 200;
	printf("HERE"); 
	//int64_t *dp = (int64_t *)malloc((sizeof(int64_t)*n*n) + sizeof(int64_t)*5);  
	int dp[5000] = {0};
	printf("HERE"); 
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	printf("HERE"); 
	
	for(int i=4;i<=(n*n);i++)
	{
		dp[i] = dp[i-1] + 2*dp[i-2] + 3*dp[i-3];
	}
	printf("HERE"); 
	/*int matrix[2005][2005] = {0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dp[i*j]%2 == 0) 
			{
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}*/
	return 0;
}
