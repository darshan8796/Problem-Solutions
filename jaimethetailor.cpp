#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
	
	int n, p;
	cin>>n>>p;
	int a[100005];
	int64_t ans = 0;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a, a + n);
	
	int max = -1;
	for(int i=0;i<n;i++)
	{
		int t = a[i]%p==0 ? a[i]/p : (a[i]/p)+1;
		if(t>max) max = t;
		else 
		{
			t=max+1;
			max = t;
		}
		 
		ans+=t;
	}
	cout<<ans<<endl;
	return 0;
}
