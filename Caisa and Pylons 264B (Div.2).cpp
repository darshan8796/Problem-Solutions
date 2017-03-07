#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[100005];
	a[0] = 0;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int ans = 0;
	int e=0;
	for(int i=1;i<=n;i++)
	{
        e+=a[i-1]-a[i];
        if(e<0) {ans-=e; e=0;}
	}
	
	cout<<ans;
	return 0;
}
