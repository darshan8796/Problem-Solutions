#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

bool comp(pair<pii, int>  a, pair<pii, int>  b)
{
	int x = a.first.first;
	int y = a.first.second;
	
	int w = b.first.first;
	int e = b.first.second;
	return ((x*x) + (y*y)) < ((w*w) + (e*e))	;
}
int main()
{
	int n, s;
	cin>>n>>s;
	
	vector< pair<pii, int> > v;
	
	int a, b, c;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		v.push_back(make_pair(make_pair(a,b), c));
	}
	
	sort(v.begin(), v.end(), comp);
	
	for(auto t : v)
	{
		//cout<<t.first.first<<" "<<t.first.second<<endl;
		s += t.second;
		if(s>=1000000)
		{
			double x = t.first.first;
			double y = t.first.second;
			
			printf("%.7f", sqrt((x*x)+(y*y)));
			return 0;
		}
	}
	
	cout<<-1;
	return 0;
}
