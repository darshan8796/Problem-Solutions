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

int n, q;

int BIT[200007] = {0};
int a[200007];
int b[200007];

void update(int i, int val)
{
	while(i<=n)
	{
		BIT[i] += val;
		i = i + (i&(-i));
	}
}

void updateBIT(int l, int r, int val)
{
	update(l, val);
	update(r+1, -val);
}

int get(int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=BIT[i];
		i = i - (i&(-i));	
	}
	return sum;
}
int main()
{
	
	scanf("%d %d", &n, &q);
	
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	sort(a, a+n+1);
	
	int t1, t2;
	while(q--)
	{
		scanf("%d %d", &t1, &t2);
		updateBIT(t1,t2,1);
	}
	for(int i=1;i<=n;i++) b[i]=get(i);
	sort(b,b+n+1);
	
	long long ans = 0;
	for(int i=1;i<=n;i++)
	{
		ans += a[i]*1LL*b[i];
	}
	
	cout<<ans;
	return 0;
}
