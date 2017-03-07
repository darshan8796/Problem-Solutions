#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int am = 0;	
	int amm = -2;	
	int a[120];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i]>amm)
		{
			amm = a[i];
			am = i;
		}
	}
	
	int b = 0;
	int bmm = 150;

	for(int i=n-1;i>=0;i--)
	{
		if(a[i]<bmm)
		{	
			bmm = a[i];
			b = i;
		}
	}
	//printf("%d %d\n", am, b);
	if(am<b)
	{
		printf("%d", am+((n-1) - b));	
	}
	else
	{
		printf("%d", am+((n-1) - b) -1);
	}
	return 0;
}


