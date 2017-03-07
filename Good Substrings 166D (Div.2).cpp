#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
	unordered_set<string> mp;
	string s;
	cin>>s;
	
	string check;
	cin>>check;
	
	int k;
	cin>>k;
	
	int bad = 0;

	for(int i=0;i<s.length();i++)
	{
		bad = 0;
		for(int j=i;j<s.length();j++)
		{
			if(check[s[j] - 'a']=='0') bad++;
			if(bad>k) break;
			else if(mp.find(s.substr(i,j-i+1))== mp.end()) mp.insert(s.substr(i,j-i+1));			 
		}
	}
	cout<<mp.size()<<endl;
	return 0;
}
