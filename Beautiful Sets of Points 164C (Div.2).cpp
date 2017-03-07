#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

unordered_set<int> st;
set< pii > ans;
int main()
{
	for(int i=1;i*i<=(100*100)+(99*99);i++) st.insert(i*i);
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int x1=0;x1<=n;x1++) for(int y1=0;y1<=m;y1++)
		for(int x2=0;x2<=n;x2++) for(int y2=0;y2<=m;y2++)
		{
			if(x1+y1<=0 || x2+y2<=0) continue;
			if(st.find((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))==st.end())
			{
				ans.insert(mp(x1,y1));
				ans.insert(mp(x2,y2));
			}
		}
	
	cout<<ans.size()<<endl;
	for(auto t: ans)
	{
		cout<<t.first<<" "<<t.second<<endl;
	}
	
	
	return 0;
}
