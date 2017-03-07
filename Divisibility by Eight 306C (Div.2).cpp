#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin>>s;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == '0' || s[i] == '8')
		{
			printf("YES\n%c",s[i]);
		}
	}
	
	for(int i=0;i<s.length();i++)
	{
		for(int j=i+1 	;j<s.length();j++)
		{
		
		}
	}
	return 0;
}

