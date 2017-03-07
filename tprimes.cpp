#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool prime[1000000];
void buil()
{
	memset(prime, true, sizeof(prime));
	for(int64_t i=2;i<1000000;i++)
	{
		if(prime[i])
		{
			for(int64_t j=i*i;i*j<=1000000;j+=i)
			{
				prime[i*j] = false;
			}
		}
	}
}
int main()
{
	buil();
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int64_t a, i;
		cin>>a;
		int64_t root = (int)sqrt(a);		
		if( a==1 || !prime[root] || (root*root)==a)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}	
	return 0;
}
