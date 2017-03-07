#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int main()
{
	int s, n;
	scanf("%d %d", &s, &n);
	
	vector<pair<int, int> > a;
	for(int i=0;i<n;i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		
		a.push_back(make_pair(t1, t2));
	}
	
	//sort(a.begin(), a.end(), comp);
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<n;i++)
		{
			pair<int, int> temp = a[i];
			if(temp.first!=-1 && s>temp.first)
			{
				s += temp.second;
				temp.first = -1;
				count++;
				a[i] = temp;
				break;
			}
			
		}
	}
	
	if(count == n)
		printf("YES");
	else
		printf("NO");		
			
	
	return 0;
}

