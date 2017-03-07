#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int a,b,c;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			scanf("%d", &c);
			if(c==1)
			{
				a = i;
				b = j;
			}
		}
	}
	printf("%d",abs(3-a)+abs(3-b));
	return 0;
}
