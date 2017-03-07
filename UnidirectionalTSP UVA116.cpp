#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstdio>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int a[12][105];
	int dir[12][105];
	
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &a[i][j]);
		
		for(int i=m-2;i>=0;i--)
		{
			for(int j=0;j<n;j++)
			{
				int t1 = a[j==0?n-1:j-1][i+1];
				int t2 = a[j][i+1];
				int t3 = a[j==n-1?0:j+1][i+1];
				
				int mn = min(min(t1,t2),t3);
				
				a[j][i] += mn;
				//cout<<a[j][i]<<" ";
				if(j==0)
				{
					if(mn == t2) dir[j][i] = 1;
					else if(mn == t3) dir[j][i] = 2;					
					else if(mn == t1) dir[j][i] = 0;
				}
				else if(j==n-1)
				{
					if(mn == t3) dir[j][i] = 2;					
					else if(mn == t1) dir[j][i] = 0;
					else if(mn == t2) dir[j][i] = 1;				
				}
				else
				{
					if(mn == t1) dir[j][i] = 0;
					else if(mn == t2) dir[j][i] = 1;
					else dir[j][i] = 2;					
				}
				
			}
			//cout<<endl;
		}
	
		int s = 1e9+7;
		int st;
		for(int i=0;i<n;i++)
		{
			//cout<<s<<" "<<a[i][0]<<endl; 
			if(a[i][0]<s)
			{
				s = a[i][0];
				st = i;
			}
		} 
		
		cout<<st+1;
		int nxt = dir[st][0];
		int p = st;
		bool space = false;
		for(int i=1;i<m;i++)
		{
			printf(" ");
			if(nxt==0)
			{
				p = (p==0?n-1:p-1);
				cout<<p+1;
			}
			else if(nxt==1) cout<<p+1;
			else 
			{
				p = (p==n-1?0:p+1);
				cout<<p+1;
			}
			nxt = dir[p][i];
		}
	cout<<endl<<s<<endl;
	}
	
	return 0;
}
