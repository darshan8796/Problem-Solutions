#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n;
int a[100005];

bool check(int j)
{
	int c;	
	for(int i=0;i<n-1;i++)
	{
		if(j==0) 
		{
			c = a[j] - a[n-1];
			j = n-1;
		}
		else 
		{
			c = a[j] - a[j-1]; 
			j--;
		}
		if(c<0) return false;
		
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	for(int i=0;i<n-1;i++)
	{
		if(a[i] > a[i+1])
		{
			if(check(i))
			{
				printf("%d", (n-1)-i);
			}
			else
			{
				printf("-1");		
			}
			return 0;
		}
	}
	
	printf("0");
	return 0;
}
