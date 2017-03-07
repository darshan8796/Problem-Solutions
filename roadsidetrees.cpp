#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[100005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int ans = 0;
	int c = 0;
	for(int i=0;i<n;i++)
	{
		ans += a[i] - c + 1;
		//printf("DEBUG %d %d %d\n", ans, a[i], c);
		if(i == n-1) break;
		
		if(a[i]>a[i+1])
		{
			//printf("DEBUG1\n");
			
			c = a[i+1];
			ans += a[i] - a[i+1] + 1;
		}
		else
		{
			//printf("DEBUG2\n");
			c = a[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
