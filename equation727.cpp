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

int preced(char c) {
	if (c == '(' || c == ')')
		return 0;
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
 	//freopen("out.txt", "w", stdout);
	string t;
	getline(cin, t);
	
	stringstream ss(t);
	int tc;
	ss>>tc;
	
	getline(cin, t);
	
	while(tc--)
	{
		stack<char> st;	
		while(1)
		{
			getline(cin, t);
			if(t == "") break;
			
			if(t == "(")
			{
				st.push(t[0]);
			}
			else if(t == ")")
			{
				while(!st.empty() && st.top()!='(')
				{
					cout<<st.top();
					st.pop();
				}
				
				st.pop();
			}
			else if(t == "+" || t == "-" || t == "*" || t == "/" )
			{
				if(st.empty() || preced(t[0])>preced(st.top())) 
				{
					st.push(t[0]);
				}
				else
				{
					while(!st.empty() && preced(t[0])<=preced(st.top()))
					{
						cout<<st.top();
						st.pop();
					}
					st.push(t[0]);
				}
				
			}
			else
			{
				cout<<t[0];		
			}
		}
		
		while(!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
		cout<<endl;
		if(tc!=0)cout<<endl;
		
	}
	return 0;
}
