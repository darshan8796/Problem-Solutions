#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	
	int ans[20] = {0};
	int a = 10;
	int b = 1;
	int na;
	int x = 0;
	while(n/a!=0)
	{
		na = n%a;
		ans[x++] = na/b;
		
		a = a*10;
		b = b*10;
	}
	ans[x++] = n/b;
	for(int i=x-1;i>=0;i--)
	{
		printf("%d ",ans[i] );
	}
	return 0;
}
