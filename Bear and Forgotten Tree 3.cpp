#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, d, h;
	cin>>n>>d>>h;
	int t = n;
	if(d>h*2)
	{
		cout<<-1;
		return 0;
	}
	
	n--;
	int x=1;
	for(int i=x;i<=h;i++)
	{
		cout<<x<<" "<<x+1<<endl;
		x=x+1;
	}
	n = n-h;
	x+=1;
	
	cout<<1<<" "<<x<<endl;
	
	for(int i=1;i<=d-h-1;i++)
	{
		cout<<x<<" "<<x+1<<endl;
		x=x+1;
	}
	x+=1;
	n=n-(d-h);
	
	for(int i=0;i<n/(d-h);i++)
	{
		cout<<1<<" "<<x<<endl;
	
		for(int i=1;i<=d-h-1;i++)
		{
			cout<<x<<" "<<x+1<<endl;
			x=x+1;
		}
		x+=1;
	}
	
	if(n%(d-h)!=0)
	{
		cout<<1<<" "<<x<<endl;
		while(x<t)
		{
			cout<<x<<" "<<x+1<<endl;
			x=x+1;
		}
	}
	return 0;
}
