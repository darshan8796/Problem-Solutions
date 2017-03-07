#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	char s[125];
	for(int i=0;i<n;i++)
	{
		scanf("%s", s);
		if(strlen(s)>10)
		{
			printf("%c%ld%c\n", s[0], strlen(s)-2, s[strlen(s)-1]);
		}
		else
		{
			printf("%s\n", s);
		}
	}
	return 0;
}
