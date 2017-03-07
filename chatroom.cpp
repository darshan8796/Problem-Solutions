#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char s[120];
	scanf("%s", s);
	
	int a[4] = {0};
	for(int i=0;i<strlen(s);i++)
	{
		switch(s[i])
		{
			case 'h':
						a[0]++;
						break;

			case 'e':
						if(a[0]>=1)
							a[1]++;
						break;

			case 'l':
						if(a[1]>=1)
							a[2]++;
						break;
						
			case 'o':
						if(a[2]>=2)
							a[3]++;
						break;
			
			default:
						break;																		
		}
		
		if(a[0]>=1 && a[1]>=1 && a[2]>=2 && a[3]>=1 )
		{
			printf("YES");
			return 0;
		}
	}
	
	printf("NO");
	return 0;
}
