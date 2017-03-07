#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

vector<vector<int> > adj(100005);
queue<int> q;

bool isVisited[100005] = {0};
int colour[100005] = {0};
int done = 0;
void dfs(int r)
{
	isVisited[r] = 1;
	
	for(vector<int>::iterator it = adj[r].begin(); it != adj[r].end() ; it++)
	{
		if(!isVisited[*it])
		{
			colour[*it] = 1 - colour[r];
			dfs(*it);
		}
		else if(colour[*it] == colour[r])
		{
			done = 1;
			return;
		}
		
	}
}
int main()
{
	int n, m;
	cin>>n>>m;
	
	int t1, t2;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	
	for(int i=1;i<=n;i++) colour[i] = -1;
	
	for(int i=1;i<=n;i++)
	{
		if(!isVisited[i])
		{
			colour[i] = 1;
			dfs(i);
		}
		
		if(done == 1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<colour[i]<<" ";
	}
	cout<<endl;
	return 0;
}

