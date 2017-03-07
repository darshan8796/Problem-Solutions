#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	if(s[0] == '-')
	{
		int i = 1;
		while(s[i]!='.') 
		{
			i++;
			if(i==s.length())
			{
				//printf("($%s.00)", s);
				break;
				cout<<"($"<<s.substr(1,s.length())<<".00)"<<endl;
				return 0;
			}
		}
		
		if((i-1)%3!=0 && (i-1)/3>0)
		{
			
		}
	}
	else
	{
	
	}
	return 0;
}

