#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	int m, n;
	cin>>m>>n;
	
	int b[101][101] ;
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		{
			b[i][j] = 1;
		}
	}
	
	int rows[m] = {0};
	int cols[n] = {0};
	int a[101][101];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j] == 0)
			{
				rows[i] = 1;
				cols[j] = 1;
				
				for(int k=0;k<m;k++) b[k][j] = 0;
				for(int k=0;k<n;k++) b[i][k] = 0;
			}
		}
	}
	
	int f = 0,g = 0;
	for(int k=0;k<m;k++)
	{
		if(rows[k] == 0) 
			{f = 1;break;} 
	}
	for(int k=0;k<n;k++)
	{
		if(cols[k] == 0) 
			{g = 1;break;}
	}
	
	if(f==0 || g==0)
	{
		for(int k=0;k<m;k++)
		{
			rows[k] = 1; 
		}
		
		for(int k=0;k<n;k++)
		{
			cols[k] =	 1;
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j] == 1 && rows[i]==1 && cols[j]==1 )
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	
	printf("YES\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
