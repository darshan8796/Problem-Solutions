#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

map<string, int> mp;
int main()
{
	int t;
	scanf("%d", &t);
	
	char c;
	char ts;
	scanf("%c", &ts);
	string s;
	while(t--)
	{
		getline(cin, s);
		if(s[0]=='+')
		{
			//cin>>s;
			//st.insert(s);
			//cout<<s[0]<<" "; 
			s = s.substr(2, s.length());
			//cout<<s<<endl;
			//cout<<"1 ";
			string p = "";
			for(int i=0;i<s.length();i++)
			{
				if((s[i]-'0')%2==0) p = p+"0";
				else p = p+"1";
			}
			
			string t2;
			for(int i=0;i<18-s.length();i++) t2.append("0");
			
			p = t2 + p;
			mp[p] += 1;
			
		}
		else if(s[0]=='-')
		{
			//cin>>s;
			//st.insert(s);
			//cout<<s[0]<<" "; 
			s = s.substr(2, s.length());
			//cout<<s<<endl;
			//cout<<"2 ";
			string p = "";
			for(int i=0;i<s.length();i++)
			{
				if((s[i]-'0')%2==0) p = p+"0";
				else p = p+"1";
			}
			
			string t2;
			for(int i=0;i<18-s.length();i++) t2.append("0");
			
			p = t2 + p;
			mp[p] -= 1;
		}
		else
		{
			//cin>>s;
			//cout<<s[0]<<" "; 
			s = s.substr(2, s.length());
			//cout<<s<<endl;
			string p = s;
			//cout<<"3 ";
			string t2;
			for(int i=0;i<18-p.length();i++) t2.append("0");
			p = t2 + p;
			cout<<mp[p]<<endl;
		}
	}
	return 0;
}
