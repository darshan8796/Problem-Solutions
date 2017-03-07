#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	char s[1001];
	scanf("%s", s);
	
	int count[26] = {0};
	for(int i=0;i<26;i++)
	{
		count[s[i] - 'a']++;
	}
	int len = strlen(s);
	int x=0;
	while(1)
	{
		if((len%2)==0)
		{
			int f = 1;
			for(int i=0;i<26;i++)
			{
				if((count[i]%2)==1)
				{
					f = 0;
					break;
				}
			}
			if(f==1)
			{
				if(x==0)
				{
					printf("First\n");
				}
				else
				{
					printf("Second\n");
				}
				return 0;
			}
			else
			{
				for(int i=0;i<26;i++)
				{
					if((count[i]%2)==1)
					{
						count[i]--;
						break;
					}
				}
				len--;
			}
			
			x=(x+1)%2;
		}
		else
		{
			int g = 0;
			for(int i=0;i<26;i++)
			{
				if((count[i]%2)==1)
				{
					g++;
					if(g>1) break;
				}
			}
			
			if(g>1)
			{
				for(int i=0;i<26;i++)
				{
					if((count[i]%2)==1)
					{
						count[i]--;
						break;
					}
				}
				len--;
			}
			else if(g==1)
			{
				if(x==0)
				{
					printf("First\n");
				}
				else
				{
					printf("Second\n");
				}
				return 0;
			}
			x=(x+1)%2;
		}
	}
	return 0;
}
