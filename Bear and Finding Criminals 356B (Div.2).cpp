#include <iostream>

using namespace std;

int main()
{
	int n, ax;
	cin>>n>>ax;
	
	int count = 0;
	
	int a[105];
	for(int i=0;i<n;i++) cin>>a[i];
	
	int l, r;
	l = ax-2;
	r = ax;
	
	if(a[ax-1] == 1) count++;
	while(l>=0 && r<n)
	{
		if(a[l] == a[r] && a[l] == 1) count+=2;
		//cout<<count<<" "<<l<<" "<<r<<" ";
		l--;
		r++;
	}
	
	while(l>=0)
	{
		if(a[l]==1) count++;
		l--;
	}
	
	while(r<n)
	{
		if(a[r]==1) count++;
		r++;
	}
	
	cout<<count;
	return 0;
}
