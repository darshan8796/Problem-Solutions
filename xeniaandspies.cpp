#include <iostream>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

int main()
{
	int n,m,s,f;
	cin>>n>>m>>s>>f;
	
	int t, si, fi;
	map<int, pair<int, int> > mp;
	for(int i=0;i<m;i++)
	{
		cin>>t>>si>>fi;
		mp[t] = make_pair(si,fi);
	}
	

	int time = 1;
	int cur = s;
	while(cur!=f)
	{
		if(mp.find(time)!=mp.end())
		{
			if(s<f)
			{
				if(!(cur>=mp[time].first-1 && cur<=mp[time].second))
				{
					cout<<"R";
					cur++;
				}
				else
				{
					//cout<<cur<<" "<<mp[time].first<<" "<<mp[time].second;
					cout<<"X";
				}
		
			}
			else
			{
				if(!(cur<=mp[time].second+1 && cur>=mp[time].first))
				{
					cout<<"L";
					cur--;
				}
				else
				{
					cout<<"X";
				}
			}
		}
		else
		{
			if(s<f)
			{
				cout<<"R";
				cur++;
			}
			else
			{
				cout<<"L";
				cur--;	
			}
		}
		time++;
	}
	return 0;
}


