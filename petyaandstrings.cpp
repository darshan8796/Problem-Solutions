#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char a[120], b[120];
	
	scanf("%s", a);
	scanf("%s", b);
	
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='A' && a[i]<='Z')
		{
			a[i] = 'a' + ( a[i] - 'A');
		}
		
		if(b[i]>='A' && b[i]<='Z')
		{
			b[i] = 'a' + ( b[i] - 'A');
		}
		
		if(a[i]<b[i])
		{
			printf("%d", -1);
			return 0;
		}
		else if(a[i]>b[i])
		{
			printf("%d", 1);
			return 0;
		}
	}
	printf("%d", 0);
	return 0;
}
