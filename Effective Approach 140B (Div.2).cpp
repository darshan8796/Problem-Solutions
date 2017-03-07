#include <iostream>
#include <cmath>
#include <map>
#include <cinttypes>

using namespace std;

map<int, int> mp;
int main()
{
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
		mp[temp] = i;
	}
	
	int m;
	cin>>m;
	
	int64_t ansa = 0;
	int64_t ansb = 0;
	for(int i=0;i<m;i++)
	{
		int t;
		cin>>t;
		ansa += mp[t];
		ansb += n-mp[t]+1;
	}
	
	cout<<ansa<<" "<<ansb<<endl;
	return 0;
}
