#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int p[10] = {0};
vector<int> a[10];

void display()
{
	for(int i=1;i<=7;i++) cout<<p[i]<<" ";
	cout<<endl;
}
int main()
{
	a[1].push_back(1);
	a[2].push_back(2);
	a[3].push_back(3);
	a[4].push_back(2);
	a[4].push_back(2);
	a[5].push_back(5);
	a[6].push_back(2);
	a[6].push_back(3);
	a[7].push_back(7);
	a[8].push_back(2);
	a[8].push_back(2);
	a[8].push_back(2);
	a[9].push_back(3);
	a[9].push_back(3);
	
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	for(int i=0;i<n;i++)
	{
		if((s[i]-'0')==0) continue;
		int q = s[i]-'0';
		q++;
		while(q--)
		{
			for(auto t: a[q])p[t]++;
		}
		//display();
	}
	
	for(int i=7;i>=2;i--)
	{
		if(p[i]>0)
		{
			for(int k=1;k<=p[i];k++) cout<<i;
			for(int j=i-1;j>=1;j--) 
			{
				for(auto t: a[j]) p[t] -= p[i];
			}	
			//display();
		}
		
	}
	return 0;
}
