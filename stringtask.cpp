#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	char s[120];
	scanf("%s", s);
	
	char ans[220];
	memset(ans, '\0', 220);
	int x=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i] = 'a' + ( s[i] - 'A');
		}
		
		if( !(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' ))
		{
			ans[x++]='.';
			ans[x++]=s[i];
		}		
	}
	
	printf("%s\n", ans);
	return 0;
}
