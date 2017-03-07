#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>


using namespace std;

int main()
{
	int n;
	cin>>n;
	
	vector< pair<int, pair<int, int> > > v;
	vector<string> vs;
	int m1=0, m2=0, m3=0;
	for(int i=0;i<n;i++)
	{
			int s;
			cin>>s;
			string name;
			cin>>name;
			
			pair<int, pair<int, int> > p;
		
			for(int i=0;i<s;i++)
			{
				string a;
				
				for(int i=0;i<6;i++)
				{
					cin>>a[i];
					if(a[i] == '-') i--;
				}
				int f = 1;
				for(int j=0;j<5;j++)
				{
					if(a[j] == a[j+1]) f = 1;
					else 
					{f = 0;
					 break;}
				}
				
				if(f==1)
				{
					p.first++;
					continue;
				}
				
				f = 1;
				for(int j=0;j<5;j++)
				{
					if(a[j] > a[j+1]) f = 1;
					else
					{f = 0;
					 break;}
				}
				
				if(f==1)
				{
					p.second.first++;
					continue;
				}
				
				p.second.second++;
			}
			
			if(p.first>m1) m1 = p.first;
			if(p.second.first>m2) m2 = p.second.first;
			if(p.second.second>m3) m3 = p.second.second;
			v.push_back(p);		
			vs.push_back(name);
	}
	
	//cout<<m1<<" "<<m2<<" "<<m3<<" "<<endl;
	cout<<"If you want to call a taxi, you should call: ";
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		//cout<<v[i].first<<" ";
		if(v[i].first == m1)
		{
			if(cnt == 0) cout<<vs[i];
			else
			{
				cout<<", "<<vs[i];
				
			}
			cnt++;
		}
		
	}
	cout<<"."<<endl;
	
	
	cout<<"If you want to order a pizza, you should call: ";
	cnt = 0;
	for(int i=0;i<n;i++)
	{
		//cout<<v[i].second.first <<" ";
		if(v[i].second.first == m2)
		{
			if(cnt == 0) cout<<vs[i];
			else
			{
				cout<<", "<<vs[i];
				
			}
			cnt++;
		}
		
	}
	cout<<"."<<endl;
	
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	cnt = 0;
	for(int i=0;i<n;i++)
	{
		//cout<<" "<<v[i].second.second <<" ";
		if(v[i].second.second == m3)
		{
			if(cnt == 0) cout<<vs[i];
			else
			{
				cout<<", "<<vs[i];
				
			}
			cnt++;
		}
		
	}
	cout<<"."<<endl;
}



