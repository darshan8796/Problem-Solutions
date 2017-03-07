#include <cstdio>

using namespace std;

int main()
{
	
	for(int i=0;i<3;i++)
	{   int a[6];
		scanf("%d%d-%d%d-%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
		printf("%d %d %d %d %d %d", a[0], a[1], a[2], a[3], a[4], a[5]);
	}
}
