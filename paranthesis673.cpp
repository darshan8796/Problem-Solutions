#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>
#include <sstream>
using namespace std;

int main()
{
 //freopen("input.txt", "r", stdin);
 //freopen("out.txt", "w", stdout);
	int n;
	string t;
	getline(cin, t);
	stringstream pars(t);
	pars>>n;
	
	for(int i=0;i<n;i++)
	{
		string a;
		//cin>>a;
		getline(cin, a);
		int f=0;
		stack<char> st;
		
		for(int i=0;i<a.length();i++)
		{
			if(a[i] == '[' || a[i] == '(')
			{
				st.push(a[i]);
			}
			else if(a[i] == ']')
			{
				if(!st.empty() && st.top() == '[') {st.pop();}
				else 
				{
					f=1;	
				}
				
			}
			else if(a[i] == ')')
			{
				if(!st.empty() && st.top() == '(') {st.pop();}
				else 
				{
					f=1;			
				}
			}
		}
		if(st.empty() && f==0) 
		{cout<<"Yes"<<endl;}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

