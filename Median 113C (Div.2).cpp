#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

int a[515];
int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	
	bool there = false;
	int mx = -1;
	int sz = n+1;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == x) there = true;
		mx  = max(mx, a[i]);
	}
	
	if(x>mx)
	{
		printf("%d", n+1);
		return 0;
	}
	
	if(!there)
	{
		ans += 1;
		a[n+1] = x;
		sz++;
	}
	 
	sort(a, a+sz);
	
	/*for(int i=1;i<=sz-1;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
	
	if(a[(sz)/2]==x)
	{
		printf("%d", ans);
		return 0;
	}
		
	int p;
	for(int i=1;i<=sz-1;i++)
	{
		if(a[i]==x)
		{
			p = i;
			break;
		}
	}
	
	if(p<(sz)/2)
	{
		int up = (upper_bound(a, a+sz, x ) - a-1);
	   	printf("%d",((sz-1-up)-1)-(up-1) + ans);
	}
	else
	{
		int lb = (lower_bound(a, a+sz, x ) - a);
		printf("%d",(lb-1)-(sz-1-lb) + ans);
	}
	return 0;
}
