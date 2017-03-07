#include <iostream>
#include <string>
#include <cstdio>
#include <cinttypes>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int64_t a[100005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int64_t s = 0;
	for(int i=1;i<n;i++)
	{
		//a[i] += s;
		
		if(a[i]<a[i-1])
		{
			s += a[i-1]-a[i];
			//a[i] = a[i-1];
		}
		//cout<<a[i]<<" "; 
	}
	
	cout<<s;
}
