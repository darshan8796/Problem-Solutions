#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[120];
	int s = 0;
	int c = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s += a[i];
		a[i] = -1*(a[i]);
	}
	
	sort(a, a+n);
	
	for(int i=0;i<n;i++)
	{
		a[i] = -1*(a[i]);
		c += a[i];
		s -= a[i];
		if(c>s)
		{
			printf("%d", i+1);
			break;
		}
	}
	return 0;
}
