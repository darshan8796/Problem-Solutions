#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[1005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int m = 200000;
	for(int i=0;i<n-1;i++)
	{
		if(m > max(a[i], a[i+1])) m = max(a[i], a[i+1]);
	}
	
	int t = a[0]<a[n-1]?a[0]:a[n-1];
	int ans = t<m?t:m;
	cout<<ans<<endl;
	return 0;
}
