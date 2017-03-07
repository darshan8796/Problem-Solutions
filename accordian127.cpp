#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <list>
using namespace std;

vector<stack<string> > v;
bool check(string a, string b)
{
	if(a[0] == b[0] || a[1] == b[1]) return true;
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	while(1)
	{
		string q;
		cin>>q;
		if(q == "#") break;
		
		v.clear();
		
		stack<string> t;
		t.push(q);
		v.push_back(t);
		for(int i=1;i<52;i++)
		{
			string a;
			cin>>a;
			stack<string> st;
			st.push(a);
			v.push_back(st);
		}
	
		
		for(int j=0;j<v.size();j++)
		{
	
			if(j-3>=0 && check(v[j].top(), v[j-3].top()))
			{
				v[j-3].push(v[j].top());
				v[j].pop();
				if(v[j].empty()) v.erase(v.begin()+j);
				j = j-4;
			}		
			else if(j-1>=0 && check(v[j].top(), v[j-1].top()))
			{
				v[j-1].push(v[j].top());
				v[j].pop();
				if(v[j].empty()) v.erase(v.begin()+j);
				j = j-2;
			}
		}
		
		printf("%d pile%s remaining:", v.size(), (v.size() == 1 ? "" : "s"));
		for(int i=0;i<v.size();i++)
		{
			
			//cout<<" "<<v[i].size();	
			printf(" %d", v[i].size());
		}
		
		printf("\n");
	}		
}
