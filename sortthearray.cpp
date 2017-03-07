#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int a[100005];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	int min = -1, max = -1;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			if(max != -1)
			{
				printf("no\n");
				return 0;
			}
			if(min == -1)
			{
				min = i;
				//printf("MIN%d\n",min);
			}
		}
		else
		{
			if(min != -1 && max == -1)
			{
				max = i;
				//printf("MAX%d\n",max);
			}
		}
	}
	
	if(min != -1 && max==-1)
	{
		max = n-1;
	}
	if(min == -1 && max ==-1)
	{
		printf("yes\n%d %d\n", min+2, max+2);
				return 0;
	}
	if(min!=0 && max!=(n-1))
	{
		if(a[max]>=a[min-1] && a[min]<=a[max+1])
		{
			printf("yes\n%d %d\n", min+1, max+1);
		}
		else
		{
			printf("no\n");
		}
		return 0;
	}
	if(min == 0 && max!=(n-1))
	{
		if(a[min]<=a[max+1])
		{
			printf("yes\n%d %d\n", min+1, max+1);
		}
		else
		{
			printf("no\n");
		}
		return 0;
	}
	if(min!=0 && max==(n-1))
	{
		if(a[max]>=a[min-1])
		{
			printf("yes\n%d %d\n", min+1, max+1);
		}
		else
		{
			printf("no\n");
		}
		return 0;
	}
	printf("yes\n%d %d\n", min+1, max+1);
	return 0;
}
