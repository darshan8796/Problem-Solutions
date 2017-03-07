#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	for(int i=n-1;i>=1;i--)
	{
		if(n%i==0)
		{
			cout<<n<<" ";
			n = i;
		}
	}
	cout<<n;
	return 0;
}

