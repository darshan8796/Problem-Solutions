#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char s[120];
	scanf("%s", s);
	int a[120];
	int x = 0, y=0;
	
	for(int i=0;i<strlen(s);i+=2)
	{
		a[x++] = s[i] - '0';
	}
	
	sort(a, a+((strlen(s)+1)/2));
	for(int i=0;i<strlen(s);i++)
	{
		if(i%2==0)
		{
			printf("%d", a[y++]);
		}	
		else
		{
			printf("+");
		}		
	}
	return 0;
}
