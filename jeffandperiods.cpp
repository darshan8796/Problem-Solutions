#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct a{
	int index;
	int value;
};

bool comp(struct a q, struct a w)
{
	if(q.value==w.value) return q.index<w.index;
	
	return q.value<w.value;
}
int main()
{
	struct a input[100005], ans[100005];

	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>input[i].value;
		input[i].index = i;
	}
	
	sort(input, input + n, comp);
	
	bool flag = true;
	int d = -1, count = 0;
	int c = input[0].value;
	int i=1, x=0;
	while(i<n)
	{
		if(input[i].value == c)
		{
			if(d==-1) 
			{
				d = input[i].index-input[i-1].index;
			}
			else
			{
				if(d!=input[i].index-input[i-1].index)
				{
					flag = false;
				}
				
			}
		}
		else
		{
			if(flag) 
			{
				ans[x].value = c;
				ans[x++].index = d==-1?0:d; 
				count++;
				
			}
			
			c = input[i].value;
			d = -1;		
			flag = true;	
		}
		i++;
	}
	if(flag) 
	{
		ans[x].value = c;
		ans[x++].index = d==-1?0:d; 
		count++;
		
	}
	cout<<count<<endl;
	for(int i=0;i<x;i++)
	{
		cout<<ans[i].value<<" "<<ans[i].index<<endl;
	}
	return 0;	
}
