/*
	 Ubiquitous Religions
	 UVA 10583
	 Union Disjoint
*/
#include <unordered_set>
#include <vector>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cstdlib>

using namespace std;

vector<pair<int, int> > uniDis;

int getParent(int i)
{
	int p;
	if(uniDis[i].first!=i) p = getParent(uniDis[i].first);
	else return i;
	
	return p;
}

void join(int i, int j)
{
	int iParent = getParent(i);
	int jParent = getParent(j);
	
	if(iParent == jParent) return;
	
	if(uniDis[iParent].second == uniDis[jParent].second)
	{
		uniDis[jParent].first = iParent;
		uniDis[iParent].second++;
	}
	else if(uniDis[iParent].second < uniDis[jParent].second)
	{
		uniDis[iParent].first = jParent;
	}
	else
	{
		uniDis[jParent].first = iParent;
	}
}

void compress(int i)
{
	int p = getParent(i);
	uniDis[i].first = p;
}

void setup(int n)
{
	uniDis.clear();
	uniDis.push_back(make_pair(-1, -1));
	for(int i=1;i<=n;i++)
	{
		uniDis.push_back(make_pair(i, 1));
	}
}

void display(int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"("<<uniDis[i].first<<" "<<uniDis[i].second<<")"<<" ";
	}
	cout<<endl;
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int n, m;
	int cnt = 1;
	while(1)
	{
		cin>>n>>m;
		
		if(n==0 && m==0) break;
		setup(n);
		for(int i=0;i<m;i++)
		{
			int t1, t2;
			cin>>t1>>t2;
			join(t1, t2);
		}
		
		unordered_set<int> st;
		for(int i=1;i<=n;i++) 
		{	
			compress(i);
			if(st.find(uniDis[i].first) == st.end()) st.insert(uniDis[i].first);
			else continue;
		}
	
		cout<<"Case "<<cnt++<<": "<<st.size()<<endl;;
	}	
	return 0;
}


