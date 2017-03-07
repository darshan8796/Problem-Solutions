#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int n;
int a[10005];
int dsu[10005] = {0};

int findp(int x)
{
	while(x!=dsu[x]) x=dsu[x];
	return x;
}
int main()
{	
	cin>>n;

	int t;
	for(int i=0;i<=n;i++) dsu[i] = i;	
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		int l = findp(i);
		int r = findp(t);
		if(l!=r)
		{
			dsu[l] = r;
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(dsu[i]==i) ans++;
	} 
	cout<<ans;
	return 0;
}
