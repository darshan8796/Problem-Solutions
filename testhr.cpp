#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int n, q;
	cin>>n>>q;
	
	/*unsigned long long int t = 2000*2000;
	t = t*t;
	cout<<t<<" "<<t%7<<endl;*/
	int *matrix = (int *)malloc(sizeof(int)*4004005);
	

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			unsigned long long int t = i*j;
			t = t*t;
			if(t%7==2 || t%7==4 ||t%7==5) 
			{	
				*(matrix + i*n + j) = 1;
				*(matrix + j*n + i) = 1;
				//matrix[i][j] = 1;
				//matrix[j][i] = 1;
			}
			else
			{
				*(matrix + i*n + j) = 0;
				*(matrix + j*n + i) = 0;
				//matrix[i][j] = 0;
				//matrix[j][i] = 0;
			}
		}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<*(matrix + i*n + j)<<" ";
		}
		cout<<endl;
	}	*/
	
	int a[4] = {0};
	//90 deg
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n/2;j++)
		{
			if(*(matrix + i*n + j) != *(matrix + i*n + n-j+1)) a[1]++;
		}
	}
	a[1] *= 2;
	
	//180 deg
	
	for(int i=1;i<=( n/2 );i++)
	{
		int k = n;
		for(int j=1;j<=n;j++)
		{
			if(*(matrix + i*n + j) != *(matrix + (n-i+1)*n + k)) a[2]++;
			k--;
		}
	}
	a[2]*=2;
	if(n%2==1)
	{for(int i=1;i<=n;i++)
	{
		if(*(matrix + (n/2 + 1)*n + i) != *(matrix + (n/2 + 1)*n + n-i+1)) a[2]++;
	}}
	
	//270 deg
	for(int i=1;i<=( n/2 );i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(*(matrix + i*n + j) != *(matrix + (n-i+1)*n + j)) a[3]++;
		}
	}
	a[3]*=2;
	
	int temp;
	/*cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3];
	*/
	for(int i=0;i<q;i++)
	{
		cin>>temp;
		if(temp%360==0) cout<<a[0]<<endl;
		else if(temp%360 == 90) cout<<a[1]<<endl;
		else if(temp%360 == 180) cout<<a[2]<<endl;
		else if(temp%360 == 270) cout<<a[3]<<endl;
	}
	free(matrix);
	/*
	int dp[100] = {0};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	int j = 3;
	cout<<0<<1<<0;
	for(int i=4;i<=35;i++)
	{
		dp[i] = dp[i-1] + 2*dp[i-3] + 3*dp[i-3];

		if(dp[i]%2==0) cout<<i%7;
		else cout<<i%7;
		j++;
		if(j%7==0) cout<<endl;			
	}*/
	return 0;
}


