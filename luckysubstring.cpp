#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a;
	cin>>a;
	
	int f=0, s=0;

	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='4') f++;
		if(a[i]=='7') s++;
	}
	
	if(f==0 && s==0) 
		{cout<<-1;return 0;}
	
	if(f>s)
		cout<<4;
	else if(s>f)
		cout<<7;
	else
		cout<<4;
	return 0;
}
