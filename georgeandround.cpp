#include <string>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	
	cin>>n>>m;
	
	int a[3005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int b[3005];
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	
	int u = 0, d = 0;
	
	while(d<m && u<n)
	{
		if(a[u] > b[d])
		{
			d++;
		} 
		else
		{
			u++;
			d++;
		}
	}
	
	if(u==n)
	{
		cout<<0;
	}
	else
	{
		cout<<n-u;
	}
	return 0;
}


