#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <utility>
using namespace std;

queue<int> q1;
queue<int> q2;

set< pair < queue<int>, queue<int> > > st;
int adj[10][10] = {0};

int main()
{
	int n;
	cin>>n;
	
	int t1;
	
	int k1, k2;
	cin>>k1;
	for(int i=0;i<k1;i++) cin>>t1, q1.push(t1);
	
	cin>>k2;	
	for(int i=0;i<k2;i++) cin>>t1, q2.push(t1);
	
	int cnt = 0;
	pair<queue<int> , queue<int> > t;
	while(!q1.empty() && !q2.empty())
	{
		int a = q1.front(); 
		
		int b = q2.front(); 
		
		t = make_pair(q1,q2);
		
		
		q1.pop();
		q2.pop();
		
		if(st.count(t))
		{
			cout<<"-1"<<endl;
			return 0;
		}
		
		st.insert(t);
		if(a>b) q1.push(b), q1.push(a);
		else q2.push(a), q2.push(b);
		cnt++;
	}
	
	if(q1.empty()) cout<<cnt<<" "<<"2";
	else  cout<<cnt<<" "<<"1";
	
	return 0;
}
