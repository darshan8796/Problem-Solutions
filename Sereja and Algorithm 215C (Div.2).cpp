#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int check[3] = {0};
int main()
{
	string s;
	cin>>s;
	
	int m;
	cin>>m;
	
	int t1, t2;
	int flag = 0;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2;
		t1--;
		t2--;
		if(t2-t1<2) 
		{
			printf("YES\n");
		 	continue;
	 	}
		for(int j=t1;j<=t2-2;j++)
		{
			check[0] = 0;
			check[1] = 0;
			check[2] = 0;
			for(int k=j;k<=j+2;k++)
			{
				if(s[k]=='x') check[0] = 1;
				else if(s[k]=='y') check[1] = 1;
				else if(s[k]=='z') check[2] = 1;
			}
			if(check[0]==0 || check[1]==0 || check[2]==0)
			{
				printf("NO\n");
				flag=1;
				break;
			}
			
		}
		if(flag==0) printf("YES\n");
		
		flag = 0;
		
	}
	return 0;
}
