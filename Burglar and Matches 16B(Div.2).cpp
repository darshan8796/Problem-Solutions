#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	vector<pair<int, int> > v;
	
	int n, m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++)
	{
		int t1, t2;
		cin>>t1>>t2;
		v.push_back(make_pair(t1, t2));
	}
	
	sort(v.begin(), v.end(), comp);
	
	int ans = 0;
	for(int i=0;i<m;i++)
	{
		if(v[i].first<n)
		{
			ans += v[i].first*v[i].second;
			n -= v[i].first;
		}
		else
		{
			ans += n*v[i].second;
			break;
		}
	}
	
	cout<<ans;
	return 0; 
}
