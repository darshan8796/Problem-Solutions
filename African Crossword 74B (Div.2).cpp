#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	char a[105][105];
	int vis[105][105];	
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		
		for(int j=0;j<s.length();j++)
		{
			a[i][j] = s[j];
			//cout<<a[i][j];
			vis[i][j] = 0;
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(k!=i && a[k][j] == a[i][j])
				{
					vis[i][j] = 1;
					vis[k][j] = 1;
				}
			}
			
			for(int k=0;k<m;k++)
			{
				if(k!=j && a[i][k] == a[i][j])
				{
					vis[i][j] = 1;
					vis[i][k] = 1;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j] == 0)
			{
				cout<<a[i][j];
			}
		}
	}
	return 0;
}
