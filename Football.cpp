#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <utility>
using namespace std;

vector<int> v[1005];
int main()
{
	int n, k;
	//cin>>n>>k;
	scanf("%d %d", &n, &k);
	int ans = 0;
	int a[1005][1005] = {0};
	
	for(int i=1;i<=n;i++)
	{
		int c = 0;
		for(int j=1;j<=n;j++)
		{
			if(i!=j && a[i][j]!=1)
			{
				v[i].push_back(j);
				ans++;
				a[i][j] = 1;
				a[j][i] = 1;
				c++;
				if(c==k) break;
			}
		}
		if(c<k)
		{
			cout<<"-1";
			return 0;
		}
	}
	
	//cout<<ans<<endl;
	printf("%d\n", ans);
	for(int i=1;i<=n;i++)
	{
		for(auto t: v[i])
		{
			//cout<<i<<" "<<t<<endl;
			printf("%d %d\n", i, t);
		}
	}
	return 0;
}
