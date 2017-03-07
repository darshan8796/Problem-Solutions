#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	while(1)
	{
		string s;
		cin>>s;
		
		if(s == "#") break;
		if(next_permutation(s.begin(),s.end()))
			cout<<s<<endl;
		else
			cout<<"No Successor"<<endl;
	}
	return 0;
}
